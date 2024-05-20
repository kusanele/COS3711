#include "reviewdata.h"
ReviewData::ReviewData(const QString &name, const QDateTime &date, bool recommended, QObject
                                                                                         *parent)
    : QObject(parent), name(name), date(date), recommended(recommended) {}
QString ReviewData::getName() const {
    return name;
}
void ReviewData::setName(const QString &name) {
    if (this->name != name) {
        this->name = name;
    }
}
QDateTime ReviewData::getDate() const {
    return date;
}

void ReviewData::setDate(const QDateTime &date) {
    if (this->date != date) {
        this->date = date;
    }
}
bool ReviewData::isRecommended() const {
    return recommended;
}
void ReviewData::setRecommended(bool recommended) {
    if (this->recommended != recommended) {
        this->recommended = recommended;
    }
}
