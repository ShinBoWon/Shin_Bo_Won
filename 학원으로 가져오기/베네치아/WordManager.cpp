#include "WordManager.h"

WordManager::WordManager()
{
}

void WordManager::Get_List()
{
	int Word_Count;
	string Spelling;
	ifstream load;
	load.open("Word.txt");
	load >> Word_Count;
	for (int i = 0; i < Word_Count; i++)
	{
		
		Word *Spell;
		Spell = new Word;
		load >> Spelling; // ��ǥ �ϰ� �ֱ� ����?.
		(*Spell).Get_Word(Spelling);
		m_vecWord.push_back(Spell);		
	}

	m_iSpeed = 0;
	m_Item_Check.Black = false;
	m_Item_Check.Speed_Up = false;
	m_Item_Check.Speed_Down = false;
	m_Item_Check.Stop = false;
	m_Timer.Stop_Check = true;
	m_Timer.Black_Check = true;

}

void WordManager::Get_Attack_Word() // �������� �ð��� ���ļ� ��������鼭 �ٸ� �ܾ� ���̶� ��ġ�� �ʰ� �ϱ�
{
	int Rand_Word, x_Location,Limit_x = WIDTH * 2 - 20;
	for (int i = 0; i <= m_vecWord.size();i++)
	{
		Rand_Word = rand() % m_vecWord.size();
		if (m_listVirus.size() != 0)
		{
			for (auto iter = m_listVirus.begin(); iter != m_listVirus.end();iter++)
			{
				if (m_vecWord[i]->Word_Out() != (*iter)->Word_Out())
				{
					Word* Virus;
					Virus = new Word;
					x_Location = rand() % Limit_x + 10;
					Virus->Pick_Up(x_Location, m_vecWord[Rand_Word]->Word_Out());
					m_listVirus.push_back(Virus);
					return;
				}
				else
				{
					--i;
					break;
				}
			}
		}
		else
		{
			Word* Virus;
			Virus = new Word;
			x_Location = rand() % Limit_x + 10;
			Virus->Pick_Up(x_Location, m_vecWord[Rand_Word]->Word_Out());
			m_listVirus.push_back(Virus);
			return;
		}
	}
}

bool WordManager::Chekcing_Word(string Word)
{
	bool Check = false, Clear_Check = true;
 	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
	{
		if ((*iter)->Word_Out() == Word)
		{
			(*iter)->Die();
			switch ((*iter)->Item_Out())
			{
			case ITEM_SPEED_DOWN: // �ð� ����.
				m_Item_Check.Speed_Down = true;
				m_Now_Item = ITEM_SPEED_DOWN;
				m_iSpeed -= 300;
				break;
			case ITEM_SPEED_UP:
				m_Item_Check.Speed_Up = true;
				m_Now_Item = ITEM_SPEED_UP;
				m_iSpeed += 300;
				break;
			case ITEM_STOP:
				m_Item_Check.Stop = true;
				m_Now_Item = ITEM_STOP;
				m_Timer.Stop_Check = false;
				break;
			case ITEM_CLEAR:
				Delete_Virus();
				Clear_Check = false;
				break;
			case ITEM_BLACK:
				m_Item_Check.Black = true;
				m_Now_Item = ITEM_BLACK;
				m_Timer.Black_Check = false;
				break;
			}

			if (Clear_Check)
			{
				delete (*iter);
				m_listVirus.erase(iter);
			}

			Check = true;
			break;

		}
	}
	Item_Aability();
	return Check;
}

void WordManager::Item_Aability()
{
	switch (m_Now_Item)
	{
	case ITEM_SPEED_DOWN: // �ð� ����.
		m_Timer.Speed_Down_Start = clock();
		if (!m_Item_Check.Speed_Down)
			m_Timer.Speed_Down_Stop = clock();

		if (m_Timer.Speed_Down_Stop - m_Timer.Speed_Down_Start <= ONE_SEC * 3)
			m_iSpeed = 0;
		break;

	case ITEM_SPEED_UP:
		m_Timer.Speed_Up_Start = clock();
		if (!m_Item_Check.Speed_Down)
			m_Timer.Speed_Up_Stop = clock();

		if (m_Timer.Speed_Up_Stop - m_Timer.Speed_Up_Start <= ONE_SEC * 3)
			m_iSpeed = 0;
		break;

	case ITEM_STOP:
		m_Timer.Stop_Start = clock();

		if (!m_Item_Check.Speed_Down)
			m_Timer.Stop_Stop = clock();

		if (m_Timer.Stop_Stop - m_Timer.Stop_Start <= ONE_SEC * 3)
			m_Timer.Stop_Check = true;
		break;

	case ITEM_BLACK:
		m_Timer.Black_Start = clock();

		if (!m_Item_Check.Speed_Down)
			m_Timer.Black_Stop = clock();

		if (m_Timer.Black_Stop - m_Timer.Black_Start <= ONE_SEC * 3)
			m_Timer.Black_Check = true;
		break;

	default:
		break;
	}
}

bool WordManager::Drop_Time_Control(int Stage, int &Life, int &Start_Time, int &Sec_Time, bool &Life_Check) // ������ �ð� ����
{
	Sec_Time = clock();
	if ( (Sec_Time - Start_Time >= ONE_SEC + m_iSpeed )  && m_Timer.Stop_Check)  // 1�ʿ� �ѹ��� �۵�
	{

		if (rand() % 3 == 0) // 3/1 Ȯ���� �ܾ ������... -> Ȯ�� ���� �����ϰ�.Stage �� ���� ������ �ܾ� Ƚ���� �ɿ������� �ݾ� �þ��
			Get_Attack_Word();

		if (!Hit_Damage())
		{
			Life--;
			Life_Check = true;
		}

		Start_Time = Sec_Time;
		return true;
	}
	return false;
}

void WordManager::Word_Drop()
{
	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
		(*iter)->Draw_Word(m_Timer.Black_Check);
}

bool WordManager::Hit_Damage()
{
	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
	{
		if (!(*iter)->Drop())
		{
			(*iter)->Die();
			delete *iter;
			m_listVirus.erase(iter);
			return false;
		}
	}
	return true;
}

void WordManager::Delete_Virus()
{
	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
	{
		(*iter)->Die();
		delete *iter;
	}
	m_listVirus.clear();
}

void WordManager::Delete_List()
{
	for (auto iter = m_vecWord.begin(); iter != m_vecWord.end(); iter++)
		delete *iter;

	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
		delete *iter;

	m_vecWord.clear();
	m_listVirus.clear();
}


WordManager::~WordManager()
{
}