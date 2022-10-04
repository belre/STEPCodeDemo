#include <stdio.h>
#include <stdlib.h>

#include <regex>
#include <iostream>

#include "SubSuperIterators.h"
#include <STEPfile.h>
#include <sdai.h>
#include <STEPattribute.h>
#include <ExpDict.h>
#include <Registry.h>
#include <errordesc.h>
#include <Registry.h>

#include <STEPcomplex.h>
#include <SdaiHeaderSchema.h>


#include "schema.h"


int main(int, char**)
{
	// SDAIレジストリオブジェクト読み取り
	auto registry = new Registry(SchemaInit);

	// インスタンスマネージャの生成
	auto instance_list = new InstMgr();

	// 一般のSTEPファイルは#1スタートなので、Indexを1進めてデータを読み取る
	instance_list->NextFileId();

	// ステップファイルを読み取り生成
	auto sfile = new STEPfile(*registry, *instance_list, "F:\\StepData\\BSP35B20-N-12.stp", false);

	// インスタンス数の分だけループ
	for (int i = 0; i < instance_list->InstanceCount(); i++) {
		SDAI_Application_instance* inst = instance_list->GetSTEPentity(i);
		std::cout << dec << i + 1 << ",";

		string express;
		const EntityDescriptor* tar_dsc = inst->getEDesc();
		std::cout << tar_dsc->QualifiedName(express) << std::endl;
	}

	return 0;
}
