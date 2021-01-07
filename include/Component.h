#ifndef COMPONENT_H
#define COMPONENT_H

#include <QVector>

class Component
{
public:
    virtual ~Component() {}
    virtual QVector<int>* GetData(void) = 0;
    virtual void SetData(QVector<int>*) = 0;
};

class DataComponent : public Component
{
    /**
      * @var Component
      */
protected:
    // Vector of the data //
    QVector<int>* _data;

public:
    DataComponent() {};
    DataComponent(QVector<int>* Vector);
    /**
      * Return the data array
      * @param void
      * @return Vector of the data
      */
    QVector<int>* GetData(void) override;
    /**
      * Set the data array
      * @param Vector of the data
      * @return void
      */
    void SetData(QVector<int>* Vector) override;

};

class Decorator : public Component {
    /**
     * @var Component
     */
protected:
    Component* component_;

public:
    Decorator(Component* component) : component_(component) { }
    /**
      * Execute the transformation
      * @param void
      * @return void
      */
    virtual void Execute(void) { return; };
};

#endif // COMPONENT_H