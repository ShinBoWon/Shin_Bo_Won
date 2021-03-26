#include "MapDraw.h" // Ward 파일 불러오는 파일 이름 Word 인거 확인해 두기
#define ITEM_COUNT 6
#define TENPERSENT 10

enum ITEM
{
	ITEM_SPEED_UP,
	ITEM_SPEED_DOWN,
	ITEM_STOP,
	ITEM_CLEAR,
	ITEM_BLACK,
	ITEM_DONT
};

class Word
{
private:
	int m_iLocation_x; // x,y 좌표 위치
	int m_iLocation_y;
	string m_strWord; // 불러 들여온 단어
	MapDraw m_Draw;

	ITEM m_Item;

public:
	void Get_Word(string Word);

	void Pick_Up(int x_Location, string Word);
	void Drop();
	bool Drop_Check();
	void Die();
	void Get_Item(int Rand);
	void Draw_Word(bool Black);

	void Black_Word();
	
	inline string Word_Out(){return m_strWord;}
	inline ITEM Item_Out() { return m_Item; }
	inline int Location() { return m_iLocation_x; }
	
	Word();
	~Word();
};