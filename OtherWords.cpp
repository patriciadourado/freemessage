#include "OtherWords.h"
#include <vector>
#include <iostream>

using namespace std;

void OtherWords::SetMessage(
    QString newMessage
)
{
    Message = newMessage;
}

QString OtherWords::GetMessage()
{
    return Message;
}

void OtherWords::ConvertMessage(
    QString Key1,
    QString Key2
)
{
    QString word = GetMessage().toUpper();
    Key1 = Key1.toUpper();
    Key2 = Key2.toUpper();

    char c0,c1;
    int j;
    for(int i = 0; i < word.length(); i++){
        for(j = 0; j < Key1.length(); j++){
            c0 = Key1[j].toLatin1();
            c1 = Key2[j].toLatin1();
            if(word[i].toLatin1() == c0){
                word[i] = c1;
            }
            else if(word[i].toLatin1() == c1){
                word[i] = c0;
            }
        }
    }

    word = word.toLower();
    SetMessage(word);
}

