#include "customproxymodel2.h"

CustomProxyModel2::CustomProxyModel2(QObject *parent)
    : QSortFilterProxyModel{parent}
{
    maxRating = 6;
    minRating = 3;
}


bool CustomProxyModel2::filterAcceptsRow(int sourceRow,
                                              const QModelIndex &sourceParent) const
{
    QModelIndex indexRating = sourceModel()->index(sourceRow, 2, sourceParent);

    return ratingInRange(sourceModel()->data(indexRating).toDouble());
}

bool CustomProxyModel2::ratingInRange(double rating) const
{
    return rating >= minRating && rating < maxRating;
}

void CustomProxyModel2::setFilterMinimumRating(double rating)
{
    minRating = rating;
    invalidateFilter();
}

void CustomProxyModel2::setFilterMaximumRating(double rating)
{
    maxRating = rating;
    invalidateFilter();
}
