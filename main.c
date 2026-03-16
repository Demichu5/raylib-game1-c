#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

#include "source/default.h"

Texture2D texturesTown[100];
Texture2D textureNPC;
Camera2D camera;

u8 map[WIDTH_TILEMAP][HEIGHT_TILEMAP];
u8 mapLogic[WIDTH_TILEMAP][HEIGHT_TILEMAP];

// 32x18 - 16:9 ratio - tiles
const u16 screenW = WIDTH_SCREEN;
const u16 screenH = HEIGHT_SCREEN;

// inicjowanie kamery, na tą chwile ok
void cameraInit(Camera2D *cam){
    cam->target = (Vector2){0, 0};
    cam->offset = (Vector2){(WIDTH_SCREEN/2), HEIGHT_SCREEN/2};
    cam->rotation = 0.0f;
    cam->zoom = 1.5f;
}

// ładowanie mapy z pliku, na tą chwile ok.
bool loadMap(){
    char bufferPath1[255];
    snprintf(bufferPath1, sizeof(bufferPath1), "%s%s", GetApplicationDirectory(), "data/settings/map.txt");
    FILE *fileMap = fopen(bufferPath1, "r");
    if(fileMap == NULL){
        return false;
    }
    for(u8 i=0;i<WIDTH_TILEMAP;i++){
        for(u8 j=0;j<HEIGHT_TILEMAP;j++){
            u32 temp;
            if(fscanf(fileMap, "%d", &temp) != 1 || temp < 0 || temp > 255){
                return false;
            }
            map[i][j] = (u8)temp;
        }
    }
    fclose(fileMap);

    char bufferPath2[255];
    snprintf(bufferPath2, sizeof(bufferPath2), "%s%s", GetApplicationDirectory(), "data/settings/logic.txt");
    FILE *fileLogic = fopen(bufferPath2, "r");
    if(fileLogic == NULL){
        return false;
    }
    for(u8 i=0;i<WIDTH_TILEMAP;i++){
        for(u8 j=0;j<HEIGHT_TILEMAP;j++){
            u32 temp;
            /*
            if(fscanf(fileLogic, "%d", &temp) != 0 || temp < 0 || temp > 255){
                return false;
            }
            */
            fscanf(fileLogic, "%d", &temp);
            mapLogic[i][j] = (u8)temp;
        }
    }
    fclose(fileLogic);
    for(u8 i=0;i<WIDTH_TILEMAP;i++){
        for(u8 j=0;j<HEIGHT_TILEMAP;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(u8 i=0;i<WIDTH_TILEMAP;i++){
        for(u8 j=0;j<HEIGHT_TILEMAP;j++){
            printf("%d ",mapLogic[i][j]);
        }
        printf("\n");
    }

    return true;
}

// renderowanie gry, in-progress
void gameRender2D(){
    ClearBackground(BLACK);

    BeginMode2D(camera);
        for(u8 i=0;i<WIDTH_TILEMAP;i++){
            for(u8 j=0;j<HEIGHT_TILEMAP;j++){
                u8 index = map[i][j];
                //printf("%d\n", index);
                DrawTexture(texturesTown[index], SPRITE_RES*j, SPRITE_RES*i, WHITE);
            }
        }
        DrawTexture(textureNPC, camera.target.x, camera.target.y, WHITE);
    EndMode2D();
}

// ładowanie tekstur, szukamy pliki ladujemy do tablicy NIERUSZAĆ
void loadTextures(const char *dirPath){
    u8 progressBar = 0;
    for(u8 i=0;i<100;i++){
        char bufferPath[255];
        char fileName[20];
        snprintf(fileName, sizeof(fileName), "tile_%04d.png", i);
        snprintf(bufferPath, sizeof(bufferPath), "%s%s%s", dirPath, "data/textures/town/", fileName);
        //printf("%s\n", bufferPath);
        
        if(FileExists(bufferPath)){
            // printf("istnieje!\n");
            texturesTown[i] = LoadTexture(bufferPath);
        }
    }
    char bufferPath[255];
    char fileName[20];
    snprintf(fileName, sizeof(fileName), "tile_0085.png");
    snprintf(bufferPath, sizeof(bufferPath), "%s%s%s", dirPath, "data/textures/dungeon/", fileName);
    textureNPC = LoadTexture(bufferPath);
}

// unload tekstur, na tą chwile ok NIERUSZAĆ
void unloadTextures(Texture2D *textures){
    for(u8 i=0;i<100;i++){
        UnloadTexture(textures[i]);
    }
}

void unloadTexture(Texture2D texture){
    UnloadTexture(texture);
}

// statystyki programu, fps'y itp. na tą chwile ok
void gameStats(bool state){
    char frameRateBuffer[16];
    u16 frameRate = GetFPS();
    sprintf(frameRateBuffer, "%d FPS", frameRate);

    char frameTimeBuffer[32];
    f32 frameTime = GetFrameTime();
    sprintf(frameTimeBuffer, "%.4f Last frame", frameTime);

    char screenBuffer[32];
    u16 screenWidth = GetScreenWidth();
    u16 screenHeight = GetScreenHeight();
    sprintf(screenBuffer, "%d x %d px", screenWidth, screenHeight);

    char cameraTargetBuffer[16];
    f32 targetx = camera.target.x;
    f32 targety = camera.target.y;
    sprintf(cameraTargetBuffer, "x:%.2f | y:%.2f", targetx, targety);

    char cameraZoomBuffer[16];
    f32 zoom = camera.zoom;
    sprintf(cameraZoomBuffer, "zoom: %.2f", zoom);

    if(state){
        DrawText(frameRateBuffer, 10, 10, 10, WHITE);
        DrawText(frameTimeBuffer, 10, 25, 10, WHITE);
        DrawText(screenBuffer, 10, 40, 10, WHITE);
        DrawText(cameraTargetBuffer, 10, 55, 10, WHITE);
        DrawText(cameraZoomBuffer, 10, 70, 10, WHITE);
    }
}

// sterowanie kamerą, na tą chwile ok
void cameraControl(f32 *moveState){
    // printf("%f\n", *moveState);
    if(*moveState > 0.35f){
        if(IsKeyDown(KEY_D) && (mapLogic[(u8)((camera.target.y)/16.0)][(u8)((camera.target.x)/16)] != 1)){
            camera.target.x += 16.0f;
            *moveState = 0.0f;
        }
        if(IsKeyDown(KEY_A) && (mapLogic[(u8)((camera.target.y)/16.0)][(u8)((camera.target.x)/16)] != 1)){
            camera.target.x -= 16.0f;
            *moveState = 0.0f;
        }
        if(IsKeyDown(KEY_S) && (mapLogic[(u8)((camera.target.y)/16.0)][(u8)((camera.target.x)/16)] != 1)){
            camera.target.y += 16.0f;
            *moveState = 0.0f;
        }
        if(IsKeyDown(KEY_W) && (mapLogic[(u8)((camera.target.y)/16.0)][(u8)((camera.target.x)/16)] != 1)){
            camera.target.y -= 16.0f;
            *moveState = 0.0f;
        }
        if(*moveState > 16.0f){
            *moveState = 0.0f;
        }
    }

    /*

    if(IsKeyDown(KEY_UP)){
        camera.zoom += 0.05f;
    }
    if(IsKeyDown(KEY_DOWN)){
        camera.zoom -= 0.05f;
    }

    */
    
    if(camera.zoom < 2.5f){
        camera.zoom = 2.5f;
    }
    if(camera.zoom > 5.0f){
        camera.zoom = 5.0f;
    }
}


int main(void) {
    InitWindow(screenW, screenH, "World of Ślimak");
    SetTargetFPS(240);

    cameraInit(&camera);

    loadMap();
    loadTextures(GetApplicationDirectory());
    f32 movementDeltaCounter = 0.0f;


    while(!WindowShouldClose()){
        // DeltaTime dla poruszania sie
        movementDeltaCounter += GetFrameTime();
        // Sterowanie kamerą przy uzyciu deltaTime();
        cameraControl(&movementDeltaCounter);

        BeginDrawing();
            gameRender2D();
            gameStats(true);
        EndDrawing();

    }
    unloadTextures(texturesTown);
    unloadTexture(textureNPC);

    CloseWindow();

    return 0;
}