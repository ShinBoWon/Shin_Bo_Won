
#include "MapDraw.h" // Ward ���� �ҷ����� ���� �̸� Word �ΰ� Ȯ���� �α�

class Word
{
private:
	int m_iLocation_x; // x,y ��ǥ ��ġ
	int m_iLocation_y;
	string m_strWord; // �ҷ� �鿩�� �ܾ�
	MapDraw m_Draw;

public:
	void Get_Word(string Wword);
	void Attack_Location(int x_Location, string Word);
	void Drop();
	void Live();
	void Die();
	

	inline string Word_Out()
	{
		return m_strWord;
	}
	Word();
	~Word();
};

