// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template <class T> class PURPLELEAF_API Node {

public:
	T Value;
	Node<T> *Next;
	Node<T> *Previous;

	Node(T v) {
		Value = v;
		Next = nullptr;
		Previous = nullptr;
	}
	~Node() {
		delete Value;
		Next = nullptr;
		Previous = nullptr;
	}

	void AddNext(T *Item) {
		Next = new Node(Item);
		Next->Previous = this;
	}

	void AddPrevious(T *Item) {
		Previous = new Node(Item);
		Previous->Next = this;
	}
};


template <class T> class PURPLELEAF_API LinkList
{
public:
	LinkList();
	~LinkList();

	Node<T> *head;
	Node<T> *last;
	int length;

	void Insert(T *value, int index);
	void AddFirst(T *value);
	void AddLast(T *value);
	T *GetFirst();
	T *Get();
	T *GetLast();
};
