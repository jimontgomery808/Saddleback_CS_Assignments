/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY & STEVEN GRENROCK
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 3/31/2015
 * ASIGNMENT #     : 9
 * ASSIGNMENT NAME : Dictionary
 *******************************************************************************/
#ifndef SKIPLIST_H_
#define SKIPLIST_H_
#include "header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
using namespace std;
const float P = 0.5;
const int MAX_LEVEL = 6;

// struct of key and city name
struct info
{
	int key;
	string city;
};

// Node in skip list
struct SkipNode
{
    info value;
    SkipNode **forward; // array of pointers

    SkipNode(int level, const info &value)
    {
        forward = new SkipNode * [level + 1];
        memset(forward, 0, sizeof(SkipNode*)*(level + 1));
        this->value = value;
    }
    ~SkipNode()
    {
        delete [] forward;
    }
};

struct SkipList
{
    SkipNode *header;
    int level;

    SkipList()
    {
        header = new SkipNode(MAX_LEVEL, info());
        level = 0;
    }
    ~SkipList()
    {
        delete header;
    }
    void print() const;
    bool contains(const int &) const;
    void insert(const info &);
    void erase(const int &);
};
float frand()
{
    return (float) rand() / RAND_MAX;
}
int random_level()
{
    static bool first = true;

    if (first)
    {
        srand( (unsigned)time( NULL ) );
        first = false;
    }

    int lvl = (int)(log(frand())/log(1.-P));
    return lvl < MAX_LEVEL ? lvl : MAX_LEVEL;
}

void SkipList::print() const
{
    const SkipNode *x = header->forward[0];
    cout << "{";
    while (x != NULL)
    {
        cout << x->value.key << " " << x->value.city;
        x = x->forward[0];
        if (x != NULL)
            cout << ",";
    }
    cout << "}\n";
}

bool SkipList::contains(const int &search_value) const
{
    const SkipNode *x = header;
    for (int i = level; i >= 0; i--)
    {
        while (x->forward[i] != NULL && x->forward[i]->value.key < search_value)
        {
            x = x->forward[i];
        }
    }
    x = x->forward[0];
    return x != NULL && x->value.key == search_value;
}

void SkipList::insert(const info &value)
{
    SkipNode *x = header;
    SkipNode *update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(SkipNode*)*(MAX_LEVEL + 1));

    for (int i = level; i >= 0; i--)
    {
        while (x->forward[i] != NULL && x->forward[i]->value.key < value.key)
        {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];

    if (x == NULL || x->value.key != value.key)
    {
        int lvl = random_level();

        if (lvl > level)
        {
			for (int i = level + 1; i <= lvl; i++)
			{
				update[i] = header;
			}
			level = lvl;
        }
        x = new SkipNode(lvl, value);
		for (int i = 0; i <= lvl; i++)
		{
			x->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = x;
		}
    }
}

void SkipList::erase(const int &value)
{
    SkipNode *x = header;
    SkipNode *update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(SkipNode*)*(MAX_LEVEL + 1));

    for (int i = level; i >= 0; i--)
    {
        while (x->forward[i] != NULL && x->forward[i]->value.key < value)
        {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];

    if (x->value.key == value)
    {
        for (int i = 0; i <= level; i++)
        {
			if (update[i]->forward[i] != x)
				break;
			update[i]->forward[i] = x->forward[i];
        }
        delete x;
        while (level > 0 && header->forward[level] == NULL)
        {
        	level--;
        }
    }
}
#endif // _SKIPLIST_H_

