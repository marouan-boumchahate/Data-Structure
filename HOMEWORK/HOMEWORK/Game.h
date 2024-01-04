#pragma once

#include "GenericLinkedList.h"

class Game
{
private:
	List<int> Scores;

public:
	void add_score(int score)
	{
		Scores.Add_Back(score);
	}

	List<int> Top_10_Scores()
	{
		if (Scores.List_Size() == 0)
		{
			cout << "No available scores!!!" << endl;
			return Scores;
		}

		List<int> top_10_scores;

		Scores.Sorting_List();

		List<int> sorted_list = Scores;

		for (unsigned short i = 1; i <= 10; i++)
		{
			top_10_scores.Add_Back(sorted_list.Back());
			sorted_list.Delete_Back();
		}

		Node<int>* current = top_10_scores.GetHead();
		unsigned short counter = 1;

		while (current != NULL)
		{
			cout << "[" << counter++ << "]  : " << current->data << endl;

			current = current->next;
		}

		return top_10_scores;
	}
};

