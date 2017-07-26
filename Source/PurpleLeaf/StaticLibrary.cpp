// Fill out your copyright notice in the Description page of Project Settings.

#include "StaticLibrary.h"
#include "stdio.h"


void UStaticLibrary::Save(FString filename, UObject *object) {
	char* fn = TCHAR_TO_ANSI(*filename);
	FILE *savedata = fopen(fn,"wb");
	fwrite(object, sizeof(object), 1, savedata);
	fclose(savedata);
}


