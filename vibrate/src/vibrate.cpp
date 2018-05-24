#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_OSX) || defined(DM_PLATFORM_ANDROID)
#include <unistd.h>
#endif

#define EXTENSION_NAME Vibrate
#define LIB_NAME "Vibrate"
#define MODULE_NAME "vibrate"

// Defold SDK
#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_ANDROID)

#include "vibrate_private.h"


static int Trigger(lua_State* L)
{
    DM_LUA_STACK_CHECK(L, 0);

    int status = VibratePlatform_Trigger();
    if( !status )
    {
        luaL_error(L, "Failed to vibrate");
    }

    return 0;
}

static const luaL_reg Module_methods[] =
{
    {"trigger", Trigger},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeVibrate(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeVibrate(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeVibrate(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeVibrate(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

#else // unsupported platforms


static dmExtension::Result AppInitializeVibrate(dmExtension::AppParams* params)
{
    dmLogInfo("Registered %s (null) Extension\n", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

static dmExtension::Result InitializeVibrate(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result AppFinalizeVibrate(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

static dmExtension::Result FinalizeVibrate(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

#endif // platforms


DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, AppInitializeVibrate, AppFinalizeVibrate, InitializeVibrate, 0, 0, FinalizeVibrate)
