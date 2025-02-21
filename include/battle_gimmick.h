#ifndef GUARD_BATTLE_GIMMICK_H
#define GUARD_BATTLE_GIMMICK_H

enum Gimmick
{
    GIMMICK_NONE,
    GIMMICK_MEGA,
    GIMMICK_ULTRA_BURST,
    GIMMICK_Z_MOVE,
    GIMMICK_DYNAMAX,
    GIMMICK_TERA,
    GIMMICKS_COUNT,
};

// gimmick Flags
#define GIMMICK_FLAG_MEGA        (1 << 0)
#define GIMMICK_FLAG_ULTRA_BURST (1 << 1)
#define GIMMICK_FLAG_Z_MOVE      (1 << 2)
#define GIMMICK_FLAG_DYNAMAX     (1 << 3)
#define GIMMICK_FLAG_TERA        (1 << 4)

// gimmick modes
#define GIMMICK_MODE_CYCLE  0
#define GIMMICK_MODE_Z_MOVE 1

struct GimmickInfo
{
    const struct SpritePalette *triggerPal;        // trigger gfx data
    const struct SpriteSheet *triggerSheet;
    const struct SpriteTemplate *triggerTemplate;
    const struct SpritePalette *indicatorPal;      // indicator gfx data
    const struct SpriteSheet *indicatorSheet;
    bool32 (*CanActivate)(u32 battler);
    void (*ActivateGimmick)(u32 battler);
};

void AssignUsableGimmicks(void);
bool32 CanActivateGimmick(u32 battler, enum Gimmick gimmick);
bool32 IsGimmickSelected(u32 battler, enum Gimmick gimmick);
void SetActiveGimmick(u32 battler, enum Gimmick gimmick);
enum Gimmick GetActiveGimmick(u32 battler);
u32 GetFirstValidGimmick(u32 battler);
bool32 ShouldTrainerBattlerUseGimmick(u32 battler, enum Gimmick gimmick);
bool32 HasTrainerUsedGimmick(u32 battler, enum Gimmick gimmick);
void SetGimmickAsActivated(u32 battler, enum Gimmick gimmick);

void ChangeGimmickTriggerSprite(u32 spriteId, u32 animId);
void CreateGimmickTriggerSprite(u32 battler, u32 gimmick);
bool32 IsGimmickTriggerSpriteActive(void);
void HideGimmickTriggerSprite(void);
void DestroyGimmickTriggerSprite(void);

void LoadIndicatorSpritesGfx(void);
u32 GetIndicatorTileTag(u32 battler);
u32 GetIndicatorPalTag(u32 battler);
void UpdateIndicatorVisibilityAndType(u32 healthboxId, bool32 invisible);
void UpdateIndicatorOamPriority(u32 healthboxId, u32 oamPriority);
void UpdateIndicatorLevelData(u32 healthboxId, u32 level);
void CreateIndicatorSprite(u32 battler);

extern const struct GimmickInfo gGimmicksInfo[];

#endif
