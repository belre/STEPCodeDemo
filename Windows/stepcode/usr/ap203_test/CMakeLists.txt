
# cmakeのバージョンを指定する
cmake_minimum_required (VERSION 3.8)

# プロジェクト名を指定する
project ("ap203_test")


# インストール時のSTEPCodeのRootディレクトリ
set(STEPCODE_ROOT_DIR "../../../")

# STEPCodeをビルドしたときのTargetディレクトリ
set(STEPCODE_TARGET_DIR_FROM_ROOT "out/build/")

# アプリケーションの登録
set(SRCS "main.cpp" )
set(HDRS)
add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})

# 展開するスキーマを指定
set(SCHEMA "ap203")


################################################################
# --- 固定のコード --- #
################################################################

# デフォルトコードのまま使用。
# STEPCODE_ROOT_DIRが相対パスの場合、絶対パスに自動的に変換される。
# 絶対パスの場合はそのまま使用する
if(EXISTS "${CMAKE_BINARY_DIR}/${STEPCODE_ROOT_DIR}/SC_VERSION.txt")
  set(STEPCODE_ROOT_DIR "${CMAKE_BINARY_DIR}/${STEPCODE_ROOT_DIR}")
  message("** STEPCODE_ROOT_DIR is a relative path; converted to absolute path: ${STEPCODE_ROOT_DIR}.")
else()
  if(NOT EXISTS "${STEPCODE_ROOT_DIR}/SC_VERSION.txt")
    message(FATAL_ERROR "****  Cannot locate STEPCODE_ROOT_DIR - try an absolute path.")
  endif(NOT EXISTS "${STEPCODE_ROOT_DIR}/SC_VERSION.txt")
endif(EXISTS "${CMAKE_BINARY_DIR}/${STEPCODE_ROOT_DIR}/SC_VERSION.txt")

# STEPCodeビルド時のTargetディレクトリも修正
set(STEPCODE_TARGET_DIR ${STEPCODE_ROOT_DIR}${STEPCODE_TARGET_DIR_FROM_ROOT})

# TRUEにすると、STEPCodeの処理部分をこのCMakeLists.txtから再ビルドする
set(SC_IS_SUBBUILD TRUE)

# ビルドタイプの指定：Debug or Release
# に応じて設定する変数を変更する
if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif(NOT DEFINED CMAKE_BUILD_TYPE)
  set(SC_BUILD_TYPE ${CMAKE_BUILD_TYPE})

# STEPCodeに必要なパスを定義する
set(STEPCODE_BUILD_DIR ${CMAKE_BINARY_DIR}/sc CACHE PATH "STEPcode build subdir")


#### ライブラリ設定 ####
# *.expのライブラリを読み込み
set(SCHEMA_PATH "${STEPCODE_ROOT_DIR}/data/${SCHEMA}/*.exp")
file(GLOB SCHEMA_FILE "${SCHEMA_PATH}")

# *.expライブラリ存在確認
if(NOT EXISTS ${SCHEMA_FILE})
  message(FATAL_ERROR "Cannot find the schema; cannot continue. Looked for ${SCHEMA_PATH} from ${CMAKE_CURRENT_LIST_DIR}")
endif(NOT EXISTS ${SCHEMA_FILE})

# CMakeでビルドしたライブラリを追加する
add_subdirectory(${STEPCODE_ROOT_DIR} "${CMAKE_CURRENT_BINARY_DIR}/sc" EXCLUDE_FROM_ALL)

#### インクルードディレクトリの指定 ####
set(STEPCODE_INCLUDE_DIR
  ${STEPCODE_ROOT_DIR}/src/base
  ${STEPCODE_ROOT_DIR}/src/clstepcore
  ${STEPCODE_ROOT_DIR}/src/cldai
  ${STEPCODE_ROOT_DIR}/src/clutils
  ${STEPCODE_ROOT_DIR}/src/cleditor
  ${STEPCODE_BUILD_DIR}/include
  ${STEPCODE_ROOT_DIR}/include
  ${CMAKE_BINARY_DIR}
  ${STEPCODE_TARGET_DIR}${CMAKE_VS_PLATFORM_NAME}-${CMAKE_BUILD_TYPE}/schemas/sdai_${SCHEMA}
)

include_directories(${STEPCODE_INCLUDE_DIR})

#### ライブラリの指定 ####
# CMakeで使用する共通ライブラリを設定する
set(STEPCODE_COMMON_LIBRARIES base stepcore stepeditor stepdai steputils
    ${STEPCODE_TARGET_DIR}${CMAKE_VS_PLATFORM_NAME}-${CMAKE_BUILD_TYPE}/lib/sdai_${SCHEMA}.lib)

# 共通ライブラリの登録
target_link_libraries(${PROJECT_NAME} ${STEPCODE_COMMON_LIBRARIES})
