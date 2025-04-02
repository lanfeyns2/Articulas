#pragma once

#include <apch.h>
#include "../core/Logging.h"

namespace Articulas
{
	class FileStreamer
	{
	public:
		FileStreamer(const char* path, bool mode)
			: m_path(path),m_mode(mode)
		{
            if (std::filesystem::exists(path))
            {
                isOpen = true;
                std::string msg = std::string(path) + " Stream is open";
                ENGINE_LOG_TRACE(msg.c_str());
            }
            else
            {
                std::string errmsg = std::string(path) + " Doesn't Exist";
                ENGINE_LOG_ERROR(errmsg.c_str());
            }
		}

        template<typename T>
		void Write(T data);
		inline std::string Read(size_t start = 1,size_t offset = 0);
    public:
        bool isOpen = false;
	private:
		const char* m_path;
		const bool m_mode;
	};

    inline std::string FileStreamer::Read(size_t size,size_t offset)
    {
        if (m_mode == false) // binary
        {
            std::fstream file;
            std::bitset<8> bits;

            file.open(m_path, std::ios::in);
            if (!file.is_open())
            {
                ENGINE_LOG_CRTICAL("Couldnt open file");
            }

            char* buffer = new char[size];

            file.seekg(offset * 8);

            file.read(buffer, size * 8);
            std::istringstream stream(buffer);

            std::string text;
            
            while (stream.good())
            {
                std::bitset<8> bits;
                stream >> bits; // Read binary sequence (8 bits at a time)
                char c = static_cast<char>(bits.to_ulong()); // Convert to ASCII value
                text += c;
            }

            return text;
        }
    }

    template<typename T>
    inline void FileStreamer::Write(T data)
    {
        std::fstream file;
        file.open(m_path, std::ios::out | std::ios::binary);

        if (!file.is_open()) {
            ENGINE_LOG_ERROR("Couldnt open file");
        }

        if (std::is_trivial<T>::value) {
            
            std::string outdata;

            if constexpr (std::is_same_v<T, const char*> || std::is_same_v<T, char*>) {
                outdata = data;
            }
            else if constexpr (std::is_same_v<T, std::string>) {
                outdata = data;
            }
            else if constexpr (std::is_arithmetic_v<T>) {
                outdata = std::to_string(data);
            }
            else {
                ENGINE_LOG_ERROR("Unsupported data type");
                file.close();
                return;
            }

            
            
            if (m_mode == 0) // binary
            {
                std::string binaryOut;

                for (char c : outdata)
                {

                    std::bitset<8> binary(static_cast<unsigned char>(c));
                    binaryOut += binary.to_string();
                }
                binaryOut.erase(binaryOut.end() - 1);
                unsigned int size = binaryOut.size();
                file.write(binaryOut.c_str(), size);
            }
        }
        else {
            ENGINE_LOG_CRTICAL("Not a trivial data");
        }

        file.close();
    }
}