#include <iostream>
#include <fstream>
#include "msgpack.hpp"
//#include <crc32c/crc32c.h>

// from bluepad32

class uni_gamepad {
    // Usage Page: 0x01 (Generic Desktop Controls)
    public: 
    
        uint8_t dpad;
        int32_t axis_x;
        int32_t axis_y;
        int32_t axis_rx;
        int32_t axis_ry;

        // Usage Page: 0x02 (Sim controls)
        int32_t brake;
        int32_t throttle;

        // Usage Page: 0x09 (Button)
        uint16_t buttons;

        // Misc buttons (from 0x0c (Consumer) and others)
        uint8_t misc_buttons;

        int32_t gyro[3];
        int32_t accel[3];

        MSGPACK_DEFINE(dpad, axis_x, axis_y, axis_rx, axis_ry, brake, throttle, buttons, misc_buttons, gyro, accel);
    };

int main(int, char**){

    uni_gamepad test = {1, 2, 3, 4, 5, 6, 7, 8, 9, {11, 12, 13}, {14, 15, 16}};

    std::cout << "Hello, from MsgBuff!\n";
   
    std::stringstream ss;
    msgpack::pack(ss, test);

    //TODO
    // calculate CRC and append to the end of the buffer
    //uint32_t crc = crc32c(0, ss.str().data(), ss.str().size());
    //ss.write(reinterpret_cast<const char*>(&crc), sizeof(crc));
    
    for (const auto &item : ss.str()) {
        std::cout << "0x" << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << +uint8_t(item) << " ";
    }
    std::cout << std::endl << std::endl;

    // Unpack
    // auto const& str = ss.str();
    // auto oh = msgpack::unpack(str.data(), str.size());
    // auto obj = oh.get();
    // std::cout << obj << std::endl;

    // write to binary file in current working directory
    std::ofstream fs("message.bin", std::ios::out | std::ios::binary);
    fs.write(ss.str().data(), ss.str().size());
    fs.close();

}
