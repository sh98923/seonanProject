#pragma once

class CubeMapEditor : public Cube
{
private:
	enum EditType
	{
		None, Wall, Coin, StartPos, Monster, Item
	};

public:
	CubeMapEditor();
	~CubeMapEditor();

	void Update();
	void Render();
	void Edit();

private:
	void SetSelectTile();

	void CreateWall();
	void CreateCoin();
	void CreateStartPos();
	void CreatePreview();

	void DeleteObject();

	void SetEdit();

	void UpdateMesh();

	void Save();
	void Load();

private:	
	POINT mapSize;
	POINT mapTiling = { 1, 1 };
	POINT selectTile;

	EditType editType = Wall;

	FloatValueBuffer* tileBuffer;

	list<GameObject*> objects;

	map<int, GameObject*> objectData;

	vector<EditType> types;

	map<EditType, GameObject*> previews;
};