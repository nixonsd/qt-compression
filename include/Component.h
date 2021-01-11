#ifndef COMPONENT_H
#define COMPONENT_H

#include <QVector>
#include <QtMath>
#include <SClass.h>
#include <exception>
#include <BinaryData.h>

class Component
{
public:
    virtual ~Component() {}
    virtual QVector<int>* GetData(void) = 0;
    virtual void SetData(QVector<int>*) = 0;

public:
    SClass* _sInfo = nullptr;
};

class DataComponent : public Component
{
    /**
      * @var Component
      */
protected:
    // Vector of the data //
    QVector<int>* _data;
    BinaryData* _binaryData;

public:
    DataComponent(void) : DataComponent(nullptr) {};
    DataComponent(QVector<int>* Vector);
    ~DataComponent(void);
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
      * Return the data array
      * @param void
      * @return Vector of the data
      */
    virtual QVector<int>* GetData(void);
    /**
      * Set the data array
      * @param Vector of the data
      * @return void
      */
    virtual void SetData(QVector<int>* Vector);
    /**
      * Execute the transformation
      * @param void
      * @return void
      */
    virtual void Execute(void) = 0;
};

#endif // COMPONENT_H