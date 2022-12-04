#ifndef OTHERWORDS_H
#define OTHERWORDS_H
#include <QString>

class OtherWords{

public:
    void ConvertMessage(
        QString Key1,
        QString Key2
    );

    void SetMessage(
        QString newMessage
    );

    QString GetMessage();

private:
    QString Message;
};

#endif // OTHERWORDS_H
