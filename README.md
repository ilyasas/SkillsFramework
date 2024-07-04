# Skills Framework for Unreal Engine
Framework for adding skills in game.

# How to use
1. Add SkillsComponent to Actor
2. Create skill derived from SkillBase class
    - For Blueprints:  Redifine Cast event and change cooldown
    - For C++:         Redifine Cast_Implementation() and set cooldown in USkillBase()
3. Add created skills to skill class list in the SkillsComponent on your actor
4. Use Skill(int index) method in SkillsComponent to cast skill

# Additional Info and methods
Skill handlers have references to owner actor (player) and to SkillsComponent (skillsComponent).

Skill handler
-
- GetCooldown(): Returns remaning cooldown
- CooldownCut(float): Cuts cooldown by given value or skips it if it's 0

Skills Component
-
- GetSkill(int): Returns skill handler by index
