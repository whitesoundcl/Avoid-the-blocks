/**
 * Created by WhitesoundCL (Luis C.)
 * For nodeMCU lolin v0.1
 * 
 */


#include <list>
#include "Graphics.h"
#include "Entity.h"
#include "EnemyEntity.h"
#include "CharacterEntity.h"
#include "Input.h"
#include "Player.h"
#include "UserInterface.h"


Graphics *gfx;
Input *input;
UserInterface *ui;
Player *player; 
CharacterEntity *characterEntity;

#define BUTTON_LEFT D7
#define BUTTON_RIGHT 0

const byte SCREEN_WIDTH = 128, SCREEN_HEIGHT = 64;
std::list<Entity *> entities;
int deaths = 0, frames = 0, framesMax = 10;
byte enemyQuantity = 3;
bool part = false, restartPending = false;

void setup()
{
    gfx = new Graphics(SCREEN_WIDTH, SCREEN_HEIGHT);
    ui = new UserInterface(SCREEN_WIDTH, SCREEN_HEIGHT);
    characterEntity = new CharacterEntity(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 1, 3, 1);
    player = new Player(BUTTON_RIGHT, BUTTON_LEFT, characterEntity, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void reset()
{
    characterEntity->getRectangle()->setPos(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 1);
    deleteEnemies(false);
    createEnemies(random(2, enemyQuantity));
    deaths++;
    ui->setDeaths(deaths);
}
void update()
{
    ui->update();
    if (ui->isDeathScreen())
    {
        return;
    }
    player->updateControl(input);
    characterEntity->loop();
    deleteEnemies(true);
    std::list<Entity *>::iterator it;
    for (it = entities.begin(); it != entities.end(); it++)
    {
        yield();
        (*it)->loop();
        if ((*it)->getRectangle()->getY() >= SCREEN_HEIGHT - 1)
        {
            if ((*it)->getRectangle()->overlaps(characterEntity->getRectangle()))
            {
                ui->setDeath(true);
                restartPending = true;
            }
        }
    }
    frames++;
    if (frames == framesMax)
    {
        createEnemies(random(2, enemyQuantity));
        frames = 0;
    }
}

void draw()
{
    gfx->firstPage();
    do
    {
        characterEntity->draw(gfx);
        std::list<Entity *>::iterator it;
        for (it = entities.begin(); it != entities.end(); it++)
        {
            (*it)->draw(gfx);
        }
        ui->draw(gfx);
    } while (gfx->nextPage());
}


void loop()
{

    if (restartPending)
    {
        if (!ui->isFilling())
        {
            reset();
            restartPending = false;
            return;
        }
    }

    if (part)
    {
        update();
    }
    else
    {
        draw();
    }

    part = !part;
}

void createEnemies(int cantidad)
{
    for (byte i = 0; i < cantidad; i++)
    {
        EnemyEntity *enemyEntity = new EnemyEntity(random(0, SCREEN_WIDTH), 0, SCREEN_WIDTH, SCREEN_HEIGHT,
                                            characterEntity);
        entities.push_back(enemyEntity);
    }
}

void deleteEnemies(bool onlyDeath)
{
    std::list<Entity *>::iterator it;
    for (it = entities.begin(); it != entities.end(); it++)
    {

        if (onlyDeath)
        {
            if (!(*it)->isLiving())
            {
                entities.remove(*it);
                it--;
            }
        }
        else
        {
            entities.remove(*it);
            it--;
        }
    }
}