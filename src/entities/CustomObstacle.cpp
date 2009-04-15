/*
 * Copyright (C) 2009 Christopho, Zelda Solarus - http://www.zelda-solarus.com
 * 
 * Zelda: Mystery of Solarus DX is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Zelda: Mystery of Solarus DX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "entities/CustomObstacle.h"

/**
 * Constructor.
 * @param name name of the custom obstacle to create
 * @param layer layer of the  to create
 * @param x x position of the  to create
 * @param y y position of the  to create
 * @param width width of the custom obstacle to create
 * @param height height of the custom obstacle to create
 * @param stops_hero true to make this entity an obstacle for the hero
 * @param stops_enemies true to make this entity an obstacle for the enemies
 * @param stops_npcs true to make this entity an obstacle for the NPCs
 * @param stops_blocks true to make this entity an obstacle for the blocks and statues
 */
CustomObstacle::CustomObstacle(const std::string &name, Layer layer, int x, int y, int width, int height,
			       bool stops_hero, bool stops_enemies, bool stops_npcs, bool stops_blocks):
  MapEntity(name, 0, layer, x, y, width, height) {

  entity_types_stopped[HERO] = stops_hero;
  entity_types_stopped[ENEMY] = stops_enemies;
  entity_types_stopped[INTERACTIVE_ENTITY] = stops_npcs;
  entity_types_stopped[BLOCK] = stops_blocks;
}

/**
 * Destructor.
 */
CustomObstacle::~CustomObstacle(void) {

}

/**
 * Returns the type of entity.
 * @return the type of entity
 */
EntityType CustomObstacle::get_type(void) {
  return CUSTOM_OBSTACLE;
}

/**
 * Returns whether this entity is an obstacle for another one.
 * @param other another entity
 * @return true if this entity is an obstacle for the other one
 */
bool CustomObstacle::is_obstacle_for(MapEntity *other) {
  return entity_types_stopped[other->get_type()];
}
