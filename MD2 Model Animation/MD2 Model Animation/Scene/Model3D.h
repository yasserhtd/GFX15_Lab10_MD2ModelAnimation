#ifndef Model3D_h__
#define Model3D_h__

#include <string>

#include <glm/glm.hpp>
#include <vector>
#include <gl\glew.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "TexturedModel.h"
#include "ModelNode.h"
#include "Texture/texture.h"
#include "GraphicsDevice\ShaderProgram.h"

//represents a scenegraph.
class Model3D
{
	//can be considered as the scenegraph's leafs
	std::vector<TexturedModel*> meshes;
	std::vector<Texture*> textures;
	ModelNode* rootNode;

	std::string GetDirectoryPath(std::string sFilePath);
	TexturedModel* convertAIMeshToTexturedModel(aiMesh* aimesh);
	Texture* convertAIMaterialToTexture(aiMaterial* aimaterial, std::string dir);
	ModelNode* convertAINodeToModelNode(aiNode* ainode, ModelNode* parent);
	glm::mat4 aiMat4x4ToglmMat4(aiMatrix4x4 aimat);
public:
	Model3D();
	~Model3D();
	bool LoadFromFile(std::string modelFileName, bool flipUVs = true);
	void Initialize();
	void Render(ShaderProgram* shaderProgram);
	void Render(ShaderProgram* shaderProgram, glm::mat4 transformationMatrix);
	void Cleanup();

};
#endif // Model3D_h__

