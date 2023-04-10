/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:50:28 by mlarra            #+#    #+#             */
/*   Updated: 2023/04/05 12:23:16 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void insertionSortVector(std::vector<int>& A, int p, int q)
{
	for (int i = p + 1; i <= q; i++)
	{
		if (A[i] < A[i - 1])
		{
			int temp = A[i];
			for (int j = p; j < i; j++)
			{
				if (A[i] < A[j])
				{
					for (int k = i; k > j; k--)
						A[k] = A[k - 1];
					A[j] = temp;
					break;
				}
			}
		}
	}
}

void mergeVector(std::vector<int>& A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int> LA(n1), RA(n2);

	for (int i = 0; i < n1; i++)
		LA[i] = A[p + i];
	for (int i = 0; i < n2; i++)
		RA[i] = A[q + 1 + i];
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i <= r; i++)
	{
		if (RIDX == n2)
		{
			A[i] = LA[LIDX];
			LIDX++;
		}
		else if (LIDX == n1)
		{
			A[i] = RA[RIDX];
			RIDX++;
		}
		else if (RA[RIDX] > LA[LIDX])
		{
			A[i] = LA[LIDX];
			LIDX++;
		}
		else
		{
			A[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void sortVector(std::vector<int>& A, int p, int r)
{
	if (r - p > K)
	{
		int q = (p + r) / 2;
		sortVector(A, q + 1, r);
		sortVector(A, p, q);
		mergeVector(A, p, q, r);
	}
	else
		insertionSortVector(A, p, r);
}

void insertionSortList(std::list<int>& A, int p, int q)
{
	for (int i = p; i < q; i++)
	{
		int tempVal = *std::next(A.begin(), i + 1);
		int j = i + 1;
		while (j > p && *std::next(A.begin(), j - 1) > tempVal)
		{
			*std::next(A.begin(), j) = *std::next(A.begin(), j - 1);
			j--;
		}
		*std::next(A.begin(), j) = tempVal;
	}
}

void mergeList(std::list<int>& A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::list<int> LA, RA;

	for (int i = 0; i < n1; i++)
		LA.push_back(*std::next(A.begin(), p + i));
	for (int i = 0; i < n2; i++)
		RA.push_back(*std::next(A.begin(), q + 1 + i));
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i <= r; i++)
	{
		if (RIDX == n2)
		{
			*std::next(A.begin(), i) = LA.front();
			LA.pop_front();
			LIDX++;
		}
		else if (LIDX == n1)
		{
			*std::next(A.begin(), i) = RA.front();
			RA.pop_front();
			RIDX++;
		}
		else if (RA.front() > LA.front())
		{
			*std::next(A.begin(), i) = LA.front();
			LA.pop_front();
			LIDX++;
		}
		else
		{
			*std::next(A.begin(), i) = RA.front();
			RA.pop_front();
			RIDX++;
		}
	}
}

void sortList(std::list<int>& A, int p, int r)
{
	if (r - p > K)
	{
		int q = (p + r) / 2;
		sortList(A, p, q);
		sortList(A, q + 1, r);
		mergeList(A, p, q, r);
	}
	else
		insertionSortList(A, p, r);
}
