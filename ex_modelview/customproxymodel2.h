#ifndef CUSTOMPROXYMODEL2_H
#define CUSTOMPROXYMODEL2_H

#include <QSortFilterProxyModel>

class CustomProxyModel2 : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    CustomProxyModel2(QObject *parent = nullptr);

    double filterMinimumRating() const { return minRating; }
    void setFilterMinimumRating(double year);

    double filterMaximumRating() const { return maxRating; }
    void setFilterMaximumRating(double year);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;


private:
    bool ratingInRange(double Rating) const;

    double minRating;
    double maxRating;
};


#endif // CUSTOMPROXYMODEL_H
