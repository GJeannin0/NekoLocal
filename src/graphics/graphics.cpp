/*
 MIT License

 Copyright (c) 2019 SAE Institute Switzerland AG

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */
#include <graphics/graphics.h>
#include <engine/engine.h>
#include "SFML/Graphics/RenderTexture.hpp"
#include "engine/log.h"
#include <sstream>
#include <Remotery.h>
#include "engine/globals.h"

namespace neko
{
void SfmlCommand::Draw(sf::RenderTarget* renderTarget)
{
    renderTarget->draw(*drawable);
}


void TilemapCommand::Draw(sf::RenderTarget* renderTarget)
{
    sf::RenderStates states;
    states.texture = texture;
    renderTarget->draw(*vertexArray, states);
}

//TODO Generate render command
void BasicGraphicsManager::Draw(sf::Drawable& drawable, int layer)
{

}
//TODO Generate render command
void BasicGraphicsManager::Draw(sf::VertexArray* vertexArray, sf::Texture* texture, int layer)
{

}
//TODO Generate render command
void BasicGraphicsManager::Draw(std::array<Command*, MAX_COMMAND_NMB>& commandBuffers_)
{

}
}
