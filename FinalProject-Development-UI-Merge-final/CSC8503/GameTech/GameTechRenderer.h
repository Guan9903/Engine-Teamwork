#pragma once
#include "../../Plugins/OpenGLRendering/OGLRenderer.h"
#include "../../Plugins/OpenGLRendering/OGLShader.h"
#include "../../Plugins/OpenGLRendering/OGLTexture.h"
#include "../../Plugins/OpenGLRendering/OGLMesh.h"
#include "../CSC8503Common/Game.h"
#include "../CSC8503Common/Debug.h"
#include "../..//CppDelegates-master/Delegates.h"

namespace NCL {
	class Maths::Vector3;
	class Maths::Vector4;
	namespace CSC8503 {

		class GameTechRenderer : public OGLRenderer	{
		public:
			GameTechRenderer(Game& world);
			~GameTechRenderer();

		protected:
			void RenderFrame()	override;

			Matrix4 SetupDebugLineMatrix()	const override;
			Matrix4 SetupDebugStringMatrix()const override;

			OGLShader*		defaultShader;

			OGLShader* paintMapShader;
			GLuint splatTex;
			Vector4 paintColour;

			Game&	gameWorld;

			void BuildObjectList();
			void SortObjectList();
			void RenderShadowMap();
			void RenderCamera(); 
			void RenderSkybox();

			void LoadSkybox();

			void Paint(PaintableGameObject* po, Matrix4 paintSpaceMatrix, Vector3 direction);
			void InitializePaintable(PaintableGameObject* po);
			void CreatePaintMap(PaintableGameObject* po);

			vector<GameObject*> activeObjects;

			OGLShader*  skyboxShader;
			OGLMesh*	skyboxMesh;
			GLuint		skyboxTex;

			//shadow mapping things
			OGLShader*	shadowShader;
			GLuint		shadowTex;
			GLuint		shadowFBO;
			Matrix4     shadowMatrix;

			Vector4		lightColour;
			float		lightRadius;
			Vector3		lightPosition;

			GLuint		paint;
		};
	}
}

