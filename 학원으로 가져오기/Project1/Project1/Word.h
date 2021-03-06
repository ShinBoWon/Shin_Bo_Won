#include "MapDraw.h" // Ward 파일 불러오는 파일 이름 Word 인거 확인해 두기

class Word
{
private:
	int m_iLocation_x; // x,y 좌표 위치
	int m_iLocation_y;
	string m_strWord; // 불러 들여온 단어
	MapDraw m_Draw;

public:
	void Get_Word(string Wword);
	void Attack_Location(int x_Location, string Word);
	bool Drop();
	void Erase_Point() { m_Draw.DrawMidText("                     ", m_iLocation_x, m_iLocation_y); };
	void Live();
	bool Die();
	

	inline string Word_Out()
	{
		return m_strWord;
	}
	Word();
	~Word();
};

