//
// Created by 10268 on 2023/1/20.
//

#ifndef GL_P1_IMAGE_H
#define GL_P1_IMAGE_H

#include "stb_image.h"
#include "iostream"
#include <glad/glad.h>
class Image{
public:
    Image(const char *filepath);
    // gl纹理变量
    unsigned int texture;
    // stb填充的纹理信息数据
    int width, height, nrChannels;
    unsigned char* data;
};

Image::Image(const char* filepath) {
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // 为当前绑定的纹理对象设置环绕、过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // 上下翻转
    stbi_set_flip_vertically_on_load(true);
    // 加载并生成纹理
    data = stbi_load(filepath, &width, &height, &nrChannels, 0);
    if (data && nrChannels == 3)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else if(data && nrChannels == 4)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}


#endif //GL_P1_IMAGE_H
