#ifndef REVIEWDATA_H
#define REVIEWDATA_H
#include <QString>
#include <QDateTime>
class ReviewData
{
public:
    ReviewData(const QString &name, const QDateTime &date, bool recommended);
    QString getName() const;
    QDateTime getDate() const;
    bool isRecommended() const;
    QString toString() const;
private:
    QString name;
    QDateTime date;
    bool recommended;
};
#endif // REVIEWDATA_H
