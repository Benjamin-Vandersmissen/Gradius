#include <iostream>
#include "Model.h"
int main(){
    models::Model* model = new models::Model();
    std::shared_ptr<controllers::Controller> controller = std::make_shared<controllers::Controller>();
    std::shared_ptr<views::View> view = std::make_shared<views::View>();
    controller->setModel(model);
    view->setModel(model);
    std::cout << "Test" << std::endl;
    return 0;
}
