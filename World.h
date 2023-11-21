#pragma once
#include <vector>

class AActor; // ������� ��Ŭ��� �Ⱦ��� ���漱��!

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

