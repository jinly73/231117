#pragma once
#include <vector>

class AActor; // 헤더에는 인클루드 안쓰고 전방선언!

class UWorld

{
public:
	UWorld();
	virtual ~UWorld();

	void SpawnActor(AActor* NewActor);
	
	void Tick();
	void Render();

	void SortRenderOrder();

	const std::vector<AActor*>& GetAllActors()
	{
		return Actors;
	}

protected:
	std::vector<AActor*> Actors;

};

