#pragma once

#include "engine/system.h"
#include <vector>
#include <asteroid/packet_type.h>

#include "asteroid/game.h"
#include "asteroid/game_manager.h"

namespace neko::net
{

struct DelayPacket
{
	float currentTime = 0.0f;
	std::unique_ptr<asteroid::Packet> packet = nullptr;
};
class SimulationClient;
class SimulationServer : public SystemInterface, public DrawImGuiInterface
{
public:
	explicit SimulationServer(std::array<std::unique_ptr<SimulationClient>, 2>& clients);
	void Init() override;
	void Update(seconds dt) override;
	void Destroy() override;
	void DrawImGui() override;
    void ReceivePacket(std::unique_ptr<asteroid::Packet> packet);
private:
    void SendPacket(std::unique_ptr<asteroid::Packet> packet);
	void ProcessReceivePacket(std::unique_ptr<asteroid::Packet> packet);



    std::vector<DelayPacket> receivedPackets_;
	std::vector<DelayPacket> sentPackets_;
	std::array<std::unique_ptr<SimulationClient>, asteroid::maxPlayerNmb>& clients_;
    std::array<ClientId, asteroid::maxPlayerNmb> clientMap_{};
	//Server game manager
	asteroid::GameManager gameManager_;
	PlayerNumber lastPlayerNumber_ = 0;
	

	float avgDelay_ = 0.25f;
	float marginDelay_ = 0.1f;
};
}
