#include "reviewdata.h"
ReviewData::ReviewData(const QString &name, const QDateTime &date, bool recommended)
    : name(name), date(date), recommended(recommended) {}
QString ReviewData::getName() const {
    return name;
}
QDateTime ReviewData::getDate() const {
    return date;
}
bool ReviewData::isRecommended() const {
    return recommended;
}
QString ReviewData::toString() const {
    return QString("Software: %1, Date: %2, Recommended: %3")
        .arg(name, date.toString(), recommended ? "Yes" : "No");
}
