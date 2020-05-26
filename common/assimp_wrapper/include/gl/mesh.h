#pragma once
#include <vector>

#include "assimp/material.h"
#include "mathematics/vector.h"
#include "gl/shader.h"
#include "gl/texture.h"

struct aiMesh;
struct aiScene;

namespace neko::assimp
{

	struct Vertex
	{
		Vec3f position;
		Vec3f normal;
		Vec2f texCoords;
	};
	struct Texture
	{
		Texture() = default;
		gl::Texture texture;
		enum class TextureType : std::uint8_t
		{
			DIFFUSE,
			SPECULAR
		};
		TextureType type = TextureType::DIFFUSE;
	};
	class Mesh
	{
	public:
		Mesh();
		void Init();
		void Draw(const gl::Shader& shader) const;
        void BindTexture(const gl::Shader& shader) const;
		void Destroy();

		void ProcessMesh(const aiMesh* mesh, const aiScene* scene,
			const std::string_view directory);
		bool IsLoaded() const;


		[[nodiscard]] unsigned int GetVao() const {return VAO;}
		[[nodiscard]] size_t GetElementsCount() const {return indices_.size();}
	protected:

		void LoadMaterialTextures(aiMaterial* material, aiTextureType aiTexture, Texture::TextureType texture,
			const std::string_view directory);
		std::vector<Vertex> vertices_;
		std::vector<unsigned int> indices_;
		std::vector<Texture> textures_;
		Job loadMeshToGpu;
		//  render data
		unsigned int VAO = 0, VBO = 0, EBO = 0;
		/**
		 * \brief This function is called on the render thread as a pre-render job
		 */
		void SetupMesh();
	};
}