#include "GameObject.hpp"

class SpaceShuttle : public GameObject
{
private:
	Model* model = nullptr;
	Texture* texture = nullptr;
public:
	void Start() override;
	void Update() override;
	void Render() override;

	~SpaceShuttle()
	{
		delete model;
		delete texture;
	}
};