//// Created by Elena Faillace on 07/07/2018.//#include "../../include/Objects/RangedWeapon.h"RangedWeapon::RangedWeapon(): projectileArray() {}bool RangedWeapon::addProjectile(const std::shared_ptr<Projectile> projectile) {    projectileArray.push_back(projectile);    return true;}std::shared_ptr<Projectile> RangedWeapon::shootProjectile() {    if(projectileArray.empty()) {        //TODO fare un controllo per quando finiscono proiettili        std::cout<<"non ci sono proiettili da sparare"<<std::endl;    }    auto p = projectileArray.back();    projectileArray.pop_back();    return p;}