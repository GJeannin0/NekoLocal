#include "net_prediction_simulation/pred_sim_engine.h"
#include "sfml_engine/physics.h"


#include <imgui.h>

namespace neko::net
{
PredSimEngine::PredSimEngine(neko::Configuration* config) :
	SfmlBasicEngine(config),
	engineExport_
{
	entityManager_,
	positionManager_,
	scaleManager_,
	rotationManager_,
	transformManager_,
	*this,
	velocitiesManager_,
	shapeManager_,
	client_
}, server_(engineExport_),
client_(engineExport_),
transformManager_(
	positionManager_, scaleManager_, rotationManager_),
	positionManager_(entityManager_),
	scaleManager_(entityManager_),
	rotationManager_(entityManager_),
	shapeManager_(entityManager_),
    spriteManager_(entityManager_, textureManager_),
	velocitiesManager_(entityManager_)
{
}

void PredSimEngine::Init()
{
	config.framerateLimit = 60u;
	config.vSync = false;
	SfmlBasicEngine::Init();


	client_.Init();
	server_.Init();
    auto texId = textureManager_.LoadTexture("data/sprites/hero/jump/hero1.png");
    for(Entity i = 0; i < actorNmb*2; i++)
    {
        spriteManager_.AddComponent(entityManager_, i);
        spriteManager_.CopyTexture(texId, i, 1);
    }
    updateDelegate_.RegisterCallback([this](float dt)
		{
			client_.Update(dt);
			server_.Update(dt);

			shapeManager_.CopyTransformPosition(positionManager_, 0, actorNmb * 2);
			shapeManager_.CopyTransformRotation(rotationManager_, 0, actorNmb * 2);
			if (!globals_.hideClient)
			{
				shapeManager_.PushCommands(graphicsManager_, 0, globals_.shownActorNmb);
			}
			shapeManager_.PushCommands(graphicsManager_, actorNmb, globals_.shownActorNmb);
			spriteManager_.CopyAllTransformPositions(entityManager_, positionManager_);
			spriteManager_.PushAllCommands(entityManager_, graphicsManager_);
		});
}

void PredSimEngine::Destroy()
{
	SfmlBasicEngine::Destroy();

	client_.Destroy();
	server_.Destroy();
}
}
