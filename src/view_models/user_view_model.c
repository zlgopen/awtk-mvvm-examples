﻿
/*This file is generated by code generator*/

#include "tkc/mem.h"
#include "tkc/utils.h"
#include "mvvm/base/utils.h"
#include "user_view_model.h"

static ret_t user_view_model_set_prop(object_t* obj, const char* name, const value_t* v) {
  user_t* auser = ((user_view_model_t*)(obj))->auser;

  if (tk_str_ieq("name", name)) {
     str_set(&(auser->name), value_str(v));

     return RET_OK;
  } else if (tk_str_ieq("nick_name", name)) {
     str_set(&(auser->nick_name), value_str(v));

     return RET_OK;
  } else if (tk_str_ieq("password", name)) {
     str_set(&(auser->password), value_str(v));

     return RET_OK;
  } else if (tk_str_ieq("registered_time", name)) {
     auser->registered_time = value_uint64(v);

     return RET_OK;
  } else if (tk_str_ieq("last_login_time", name)) {
     auser->last_login_time = value_uint64(v);

     return RET_OK;
  }
  
  return RET_NOT_FOUND;
}


static ret_t user_view_model_get_prop(object_t* obj, const char* name, value_t* v) {
  user_t* auser = ((user_view_model_t*)(obj))->auser;

  if (tk_str_ieq("name", name)) {
     value_set_str(v, auser->name.str);
     return RET_OK;
  } else if (tk_str_ieq("nick_name", name)) {
     value_set_str(v, auser->nick_name.str);
     return RET_OK;
  } else if (tk_str_ieq("password", name)) {
     value_set_str(v, auser->password.str);
     return RET_OK;
  } else if (tk_str_ieq("registered_time", name)) {
     value_set_uint64(v, auser->registered_time);
     return RET_OK;
  } else if (tk_str_ieq("last_login_time", name)) {
     value_set_uint64(v, auser->last_login_time);
     return RET_OK;
  }

  return RET_NOT_FOUND;
}


static bool_t user_view_model_can_exec(object_t* obj, const char* name, const char* args) {

  return FALSE;
}

static ret_t user_view_model_exec(object_t* obj, const char* name, const char* args) {

  return RET_NOT_FOUND;
}

static ret_t user_view_model_on_destroy(object_t* obj) {
  user_view_model_t* vm = (user_view_model_t*)(obj);
  return_value_if_fail(vm != NULL, RET_BAD_PARAMS);

  
  user_destroy(vm->auser);

  return view_model_deinit(VIEW_MODEL(obj));
}

static const object_vtable_t s_user_view_model_vtable = {
  "user_view_model_t",
  "user_view_model_t",
  sizeof(user_view_model_t),
  FALSE,
  user_view_model_on_destroy,
  NULL,
  user_view_model_get_prop,
  user_view_model_set_prop,
  NULL,
  NULL,
  user_view_model_can_exec,
  user_view_model_exec
};

view_model_t* user_view_model_create_with(user_t* auser) {
  object_t* obj = object_create(&s_user_view_model_vtable);
  view_model_t* vm = view_model_init(VIEW_MODEL(obj));
  user_view_model_t* user_view_model = (user_view_model_t*)(vm);

  return_value_if_fail(vm != NULL, NULL);

  user_view_model->auser = auser;
  

  return vm;
}

ret_t user_view_model_attach(view_model_t* vm, user_t* auser) {
  user_view_model_t* user_view_model = (user_view_model_t*)(vm);
  return_value_if_fail(vm != NULL, RET_BAD_PARAMS);

  user_view_model->auser = auser;

  return RET_OK;
}

view_model_t* user_view_model_create(navigator_request_t* req) {
  user_t* auser = user_create();
  return_value_if_fail(auser != NULL, NULL);

  return user_view_model_create_with(auser);
}
