#pragma once


class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape = ' ');
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	//accessor
	inline int GetX() const { return X; }
	inline int GetY() const { return Y; }

	inline void SetX(int NewX) { X = NewX; }
	inline void SetY(int NewY) { X = NewY; }

	bool operator < (const AActor& RHS) const
	{
		return this->SortOrder < RHS.SortOrder;
	}

	bool operator > (const AActor& RHS) const
	{
		return this->SortOrder > RHS.SortOrder;
	}

	int SortOrder;
	bool bCollide;

protected:
	int X;
	int Y;

	char Shape;
};