#ifndef CASE_H
#define CASE_H

#include "entity.h"
/**
 * \brief The Case class
 */
class Case{

private:
    Entity * en_;
    bool hole_;
    bool available_;
public:


    explicit Case();

    /**
     * \brief setEntity of the case
     * \param en a Entity for case.
     */
    void setEntity(Entity * en);

    /**
     * \brief getEntity give the entity in the case.
     * \return the entity in the case.
     */
    Entity * getEntity() const;
    /**
     * \brief isHole get if the case is a hole.
     * \return a boolean ,true is a hole.
     */
    bool isHole() const;
    /**
     * \brief setHole change the case if is a hole or not.
     */
    void setHole();
    /**
     * \brief getDispo give if the case is available.
     * \return a boolean, true if as not a hole and en_ is en nullptr.
     */
    bool isAvailable() const;

    bool isDispo() const;

    ~Case();
};

#endif // CASE_H

