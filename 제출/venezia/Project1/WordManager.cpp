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
	m_iMake_Count = 1;
	m_iPercent = 4;
}

bool WordManager::Word_Size_Check(int Location_x,int Word_Location,string Word)
{
	if (Location_x >= Word_Location && Location_x <= Word_Location + Word.size())
		return false;
	else
		return true;
}

void WordManager::Get_Attack_Word() // �������� �ð��� ���ļ� ��������鼭 �ٸ� �ܾ� ���̶� ��ġ�� �ʰ� ���� ��ġ���� �������� �ʰ� �ϱ�.
{
	int Rand_Word, x_Location,Limit_x = WIDTH * 2 - 22, Word_Count = m_vecWord.size() - 1;
	bool Same_Check = false;
	while (1)
	{
		Rand_Word =  rand() % Word_Count;
		x_Location = rand() % Limit_x;
		for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
		{
			if ((*iter)->Word_Out() != m_vecWord[Rand_Word]->Word_Out())
			{
				Same_Check = true;
				break;
			}
		}

		if (Same_Check || m_listVirus.size() == 0)
		{
			Word* Virus;
			Virus = new Word;
			x_Location = rand() % Limit_x + 2;
			Virus->Pick_Up(x_Location, m_vecWord[Rand_Word]->Word_Out());
			m_listVirus.push_back(Virus);
			break;
		}
	}
	
}

bool WordManager::Chekcing_Word(string Word)
{
	bool Check = false, Clear_Check = true , item_Checking = false;
 	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
	{
		if ((*iter)->Word_Out() == Word)
		{
			(*iter)->Die();
			switch ((*iter)->Item_Out())
			{
			case ITEM_SPEED_DOWN: // �ð� ����.
				m_Item_Check.Speed_Down = true;
				item_Checking = true;
				break;
			case ITEM_SPEED_UP:
				m_Item_Check.Speed_Up = true;
				item_Checking = true;
				break;
			case ITEM_STOP:
				m_Item_Check.Stop = true;
				item_Checking = true;
				break;
			case ITEM_CLEAR:
				Delete_Virus();
				Clear_Check = false;
				break;
			case ITEM_BLACK:
				m_Item_Check.Black = true;
				item_Checking = true;
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
	
	if (item_Checking)
		Item_Ability();

	return Check;
}

void WordManager::Item_Ability()
{
	// �ӵ� �ٿ� �����Ƽ 
	if (m_Item_Check.Speed_Down)
	{
		m_Timer.Speed_Down_Start = clock();
		m_iSpeed += ABILITY;
	}
	// �ӵ� �� �����Ƽ
	if (m_Item_Check.Speed_Up)
	{
		m_Timer.Speed_Up_Start = clock();
		m_iSpeed -= ABILITY;
	}
	// ���� �����Ƽ
	if (m_Item_Check.Stop)
	{
		m_Timer.Stop_Start = clock();
		m_Timer.Stop_Check = false;
	}
	// �ܾ� ������ �����Ƽ
	if (m_Item_Check.Black)
	{
		Black_Item();
		m_Timer.Black_Start = clock();
		m_Timer.Black_Check = false;
	}
}

void WordManager::Black_Item()
{
	for (auto iter = m_listVirus.begin(); iter != m_listVirus.end(); iter++)
		(*iter)->Black_Word();
}

void WordManager::Item_Abliity_Check()
{
	if (m_Item_Check.Speed_Down)
	{
		m_Timer.Speed_Down_Check = clock();
		if (m_Timer.Speed_Down_Check - m_Timer.Speed_Down_Start >= ONE_SEC * 3)
		{
			m_iSpeed -= ABILITY;
			m_Timer.Speed_Down_Check = 0;
			m_Timer.Speed_Down_Start = 0;
			m_Item_Check.Speed_Down = false;
		}
	}
	if (m_Item_Check.Speed_Up)
	{
		m_Timer.Speed_Up_Check = clock();
		if (m_Timer.Speed_Up_Check - m_Timer.Speed_Up_Start >= ONE_SEC * 3)
		{
			m_iSpeed += ABILITY;
			m_Timer.Speed_Up_Check = 0;
			m_Timer.Speed_Up_Start = 0;
			m_Item_Check.Speed_Up = false;
		}
	}

	if (m_Item_Check.Stop)
	{
		m_Timer.Stop_Time_Check = clock();
		if (m_Timer.Stop_Time_Check - m_Timer.Stop_Start >= ONE_SEC * 3)
		{
			m_Timer.Stop_Time_Check = 0;
			m_Timer.Stop_Start = 0;
			m_Timer.Stop_Check = true;
			m_Item_Check.Stop = false;			
		}
	}

	if (m_Item_Check.Black)
	{
		m_Timer.Black_Time_Check = clock();
		if (m_Timer.Black_Time_Check - m_Timer.Black_Start >= ONE_SEC * 2)
		{
			m_Timer.Black_Time_Check = 0;
			m_Timer.Black_Start = 0;
			m_Timer.Black_Check = true;
			m_Item_Check.Black = false;
		}
	}
}

void WordManager::Check_Stage(int Stage)
{
	if (Stage / 4 + 1 > m_iMake_Count)
		m_iMake_Count++;

	if (m_iPercent <= 1)
		m_iPercent += 3;
	else
		m_iPercent--;
	
}

void WordManager::Create_Word_Count(int Stage)
{
	for (int i = 0; i < m_iMake_Count; i++) // Ƚ���� ������ �������� ���� ���� 1 ~ 3 Stage = �ѹ���  4~ 7 Stage 2�� 8 ~ 10 3�� �ݺ�
	{
		if (rand() % m_iPercent == 0) // Ȯ���� ���ڰ� ũ�� Ŭ ���� ���� ����  || �ݺ� Ƚ���� �þ �� �ʱ�ȭ
			Get_Attack_Word();
	}
}

bool WordManager::Drop_Time_Control(int Stage,int &Start_Time, int &Sec_Time, bool &Life_Check) // ������ �ð� ����
{
	Item_Abliity_Check(); //������ ��� �ð� üũ
	Sec_Time = clock();

	if ( (Sec_Time - Start_Time >= ONE_SEC + m_iSpeed  - ( Stage - 1) * 50)  && m_Timer.Stop_Check)  // 1�ʿ� �ѹ��� �۵�
	{
		Create_Word_Count(Stage);
		
		if (!Hit_Damage())
			Life_Check = true;

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
		if (!(*iter)->Drop_Check())
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