#include <vector>

#include "AbstractCommand.h"
#include "GameObject.h"

class DeleteStaticObjCommand : public AbstractCommand {
private:
    GameObject* obj;
    std::vector<GameObject*>* vecStaticObj;
public:
    DeleteStaticObjCommand(GameObject* _obj, std::vector<GameObject*>& _vecStaticObj) : obj(_obj), vecStaticObj(&_vecStaticObj){};
    void Execute() override;
};