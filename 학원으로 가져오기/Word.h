
#include "MapDraw.h" // Ward ���� �ҷ����� ���� �̸� Word �ΰ� Ȯ���� �α�

class Word
{
private:
	int m_iLocation_x; // x,y ��ǥ ��ġ
	int m_iLocation_y;
	string m_strWard; // �ҷ� �鿩�� �ܾ�
	MapDraw m_Draw;

public:
	void Drop();
	void Live();
	void Die();
	Word();
	~Word();
};

