#include "GameObject.hpp"

class SpaceShuttle : public GameObject
{
private:
	Model* model = nullptr;
	Texture* texture = nullptr;

	float speed = 45.0f;

	void FlyAround();

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