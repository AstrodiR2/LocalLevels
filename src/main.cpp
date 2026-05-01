#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

        auto label = CCLabelBMFont::create("Local\nLevels", "bigFont.fnt");
        label->setScale(0.35f);
        label->setAlignment(kCCTextAlignmentCenter);

        auto btn = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::onLocalLevels)
        );
        btn->addChild(label);
        label->setPosition(btn->getContentSize() / 2);

        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition(winSize.width - 35, 65);
        this->addChild(menu, 10);

        return true;
    }

    void onLocalLevels(CCObject*) {
        auto search = GJSearchObject::create(SearchType::SavedLevels);
        auto scene = LevelBrowserLayer::scene(search);
        CCDirector::get()->pushScene(CCTransitionFade::create(0.5f, scene));
    }
};
