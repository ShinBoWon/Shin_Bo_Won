
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
	void Drop();
	void Live();
	void Die();
	Word();
	~Word();
};

