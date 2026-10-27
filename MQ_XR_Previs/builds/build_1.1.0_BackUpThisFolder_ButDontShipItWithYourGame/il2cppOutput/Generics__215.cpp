#include "pch-cpp.hpp"





template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*,T1,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj,p1,invokeData.method);
	}
};
template <typename T1, typename T2, typename T3>
struct VirtualActionInvoker3
{
	typedef void (*Action)(void*,T1,T2,T3,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj,p1,p2,p3,invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,invokeData.method);
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct VirtualFuncInvoker4
{
	typedef R (*Func)(void*,T1,T2,T3,T4,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3, T4 p4)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj,p1,p2,p3,p4,invokeData.method);
	}
};
template <typename T1, typename T2>
struct InterfaceActionInvoker2
{
	typedef void (*Action)(void*,T1,T2,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
	}
};
template <typename T1, typename T2, typename T3, typename T4>
struct InterfaceActionInvoker4
{
	typedef void (*Action)(void*,T1,T2,T3,T4,const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2, T3 p3, T4 p4)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj,p1,p2,p3,p4,invokeData.method);
	}
};
template <typename R, typename T1>
struct InterfaceFuncInvoker1
{
	typedef R (*Func)(void*,T1,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,p1,invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct InterfaceFuncInvoker2
{
	typedef R (*Func)(void*,T1,T2,const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj,p1,p2,invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, params[0]);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, params[1]);
	}
};
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2;
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		R ret;
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87;
struct Dictionary_2_t9FA6D82CAFC18769F7515BB51D1C56DAE09381C3;
struct Dictionary_2_t403063CE4960B4F46C688912237C6A27E550FF55;
struct Dictionary_2_tE1603CE612C16451D1E56FF4D4859D4FE4087C28;
struct Func_1_tD59A12717D79BFB403BF973694B1BE5B85474BD1;
struct Predicate_1_t8342C85FF4E41CD1F7024AC0CDC3E5312A32CB12;
struct Predicate_1_t7F48518B008C1472339EEEBABA3DE203FE1F26ED;
struct TaskFactory_1_tFAEAC22A1E986463E6956C344A78A7C7197288E0;
struct Task_1_t824317F4B958F7512E8F7300511752937A6C6043;
struct Task_1_tDF1FF540D7D2248A08580387A39717B7FB7A9CF9;
struct VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B;
struct VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA;
struct VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A;
struct VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0;
struct VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482;
struct VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23;
struct VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5;
struct VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5;
struct VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD;
struct VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229;
struct VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399;
struct VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595;
struct AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A;
struct AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;
struct AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E;
struct Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07;
struct Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B;
struct CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57;
struct ContextCallback_tE8AFBDBFCC040FDA8DA8C1EEFE9BD66B16BDA007;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0;
struct DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A;
struct Delegate_t;
struct IAsyncStateMachine_t0680C7F905C553076B552D5A1A6E39E2F0F36AA2;
struct ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IFormatProvider_tC202922D43BFF3525109ABF3FB79625F5646AB52;
struct IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47;
struct IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4;
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct SendOrPostCallback_t5C292A12062F24027A98492F52ECFE9802AA6F0E;
struct StackGuard_tACE063A1B7374BDF4AD472DE4585D05AD8745352;
struct String_t;
struct StringBuilder_t;
struct TaskFactory_tF781BD37BE23917412AD83424D1497C7C1509DF0;
struct TaskScheduler_t3F0550EBEF7C41F74EC8C08FF4BED0D8CE66006E;
struct TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4;
struct Type_t;
struct VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94;
struct VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA;
struct VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC;
struct VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct WaitCallback_tFB2C7FD58D024BBC2B0333DC7A4CB63B8DEBD5D3;
struct ContingentProperties_t3FA59480914505CEA917B1002EC675F29D0CB540;

IL2CPP_EXTERN_C RuntimeClass* AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringBuilder_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Type_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869;
IL2CPP_EXTERN_C String_t* _stringLiteral491788442E76F5D7830F0DBFCF8EDD98854F636F;
IL2CPP_EXTERN_C String_t* _stringLiteral695F5F858DF14780BC5525F0AA16CE70EB9C45E8;
IL2CPP_EXTERN_C String_t* _stringLiteralBF92C939C85D8888B68A1C0E975839B22C2F1CA0;
IL2CPP_EXTERN_C String_t* _stringLiteralE310274B02A605A3985345944A620D7D2E019A1A;
IL2CPP_EXTERN_C const RuntimeMethod* Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_com;
struct CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_pinvoke;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com;
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A;
struct AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2;
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct EmptyArray_1_tF2F83411E5DC963DBFFD1F75B10B58A1ED224DD5  : public RuntimeObject
{
};
struct AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD  : public RuntimeObject
{
	int32_t ___count;
};
struct AccessorSparseValues_t44A45125EF7E14021915DACA49F5CCECF5948071  : public RuntimeObject
{
	uint32_t ___bufferView;
	int32_t ___byteOffset;
};
struct Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B  : public RuntimeObject
{
	int32_t ___POSITION;
	int32_t ___NORMAL;
	int32_t ___TANGENT;
	int32_t ___TEXCOORD_0;
	int32_t ___TEXCOORD_1;
	int32_t ___TEXCOORD_2;
	int32_t ___TEXCOORD_3;
	int32_t ___TEXCOORD_4;
	int32_t ___TEXCOORD_5;
	int32_t ___TEXCOORD_6;
	int32_t ___TEXCOORD_7;
	int32_t ___TEXCOORD_8;
	int32_t ___COLOR_0;
	int32_t ___JOINTS_0;
	int32_t ___WEIGHTS_0;
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0  : public RuntimeObject
{
	bool ___m_isReadOnly;
	int32_t ___cultureID;
	int32_t ___parent_lcid;
	int32_t ___datetime_index;
	int32_t ___number_index;
	int32_t ___default_calendar_type;
	bool ___m_useUserOverride;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo;
	String_t* ___m_name;
	String_t* ___englishname;
	String_t* ___nativename;
	String_t* ___iso3lang;
	String_t* ___iso2lang;
	String_t* ___win3lang;
	String_t* ___territory;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___native_calendar_names;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo;
	void* ___textinfo_data;
	int32_t ___m_dataItem;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___parent_culture;
	bool ___constructed;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___cached_serialized_form;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D* ___m_cultureData;
	bool ___m_isInherited;
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke
{
	int32_t ___m_isReadOnly;
	int32_t ___cultureID;
	int32_t ___parent_lcid;
	int32_t ___datetime_index;
	int32_t ___number_index;
	int32_t ___default_calendar_type;
	int32_t ___m_useUserOverride;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo;
	char* ___m_name;
	char* ___englishname;
	char* ___nativename;
	char* ___iso3lang;
	char* ___iso2lang;
	char* ___win3lang;
	char* ___territory;
	char** ___native_calendar_names;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo;
	void* ___textinfo_data;
	int32_t ___m_dataItem;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_pinvoke* ___parent_culture;
	int32_t ___constructed;
	Il2CppSafeArray* ___cached_serialized_form;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_pinvoke* ___m_cultureData;
	int32_t ___m_isInherited;
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com
{
	int32_t ___m_isReadOnly;
	int32_t ___cultureID;
	int32_t ___parent_lcid;
	int32_t ___datetime_index;
	int32_t ___number_index;
	int32_t ___default_calendar_type;
	int32_t ___m_useUserOverride;
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___numInfo;
	DateTimeFormatInfo_t0457520F9FA7B5C8EAAEB3AD50413B6AEEB7458A* ___dateTimeInfo;
	TextInfo_tD3BAFCFD77418851E7D5CB8D2588F47019E414B4* ___textInfo;
	Il2CppChar* ___m_name;
	Il2CppChar* ___englishname;
	Il2CppChar* ___nativename;
	Il2CppChar* ___iso3lang;
	Il2CppChar* ___iso2lang;
	Il2CppChar* ___win3lang;
	Il2CppChar* ___territory;
	Il2CppChar** ___native_calendar_names;
	CompareInfo_t1B1A6AC3486B570C76ABA52149C9BD4CD82F9E57* ___compareInfo;
	void* ___textinfo_data;
	int32_t ___m_dataItem;
	Calendar_t0A117CC7532A54C17188C2EFEA1F79DB20DF3A3B* ___calendar;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_marshaled_com* ___parent_culture;
	int32_t ___constructed;
	Il2CppSafeArray* ___cached_serialized_form;
	CultureData_tEEFDCF4ECA1BBF6C0C8C94EB3541657245598F9D_marshaled_com* ___m_cultureData;
	int32_t ___m_isInherited;
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct NamedObject_t907D3C13C4675E1432B946C6306227637A38EA9D  : public RuntimeObject
{
	String_t* ___name;
};
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___numberGroupSizes;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___currencyGroupSizes;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___percentGroupSizes;
	String_t* ___positiveSign;
	String_t* ___negativeSign;
	String_t* ___numberDecimalSeparator;
	String_t* ___numberGroupSeparator;
	String_t* ___currencyGroupSeparator;
	String_t* ___currencyDecimalSeparator;
	String_t* ___currencySymbol;
	String_t* ___ansiCurrencySymbol;
	String_t* ___nanSymbol;
	String_t* ___positiveInfinitySymbol;
	String_t* ___negativeInfinitySymbol;
	String_t* ___percentDecimalSeparator;
	String_t* ___percentGroupSeparator;
	String_t* ___percentSymbol;
	String_t* ___perMilleSymbol;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___nativeDigits;
	int32_t ___m_dataItem;
	int32_t ___numberDecimalDigits;
	int32_t ___currencyDecimalDigits;
	int32_t ___currencyPositivePattern;
	int32_t ___currencyNegativePattern;
	int32_t ___numberNegativePattern;
	int32_t ___percentPositivePattern;
	int32_t ___percentNegativePattern;
	int32_t ___percentDecimalDigits;
	int32_t ___digitSubstitution;
	bool ___isReadOnly;
	bool ___m_useUserOverride;
	bool ___m_isInvariant;
	bool ___validForParseAsNumber;
	bool ___validForParseAsCurrency;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct StringBuilder_t  : public RuntimeObject
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___m_ChunkChars;
	StringBuilder_t* ___m_ChunkPrevious;
	int32_t ___m_ChunkLength;
	int32_t ___m_ChunkOffset;
	int32_t ___m_MaxCapacity;
};
struct Task_t751C4CC3ECD055BABA8A0B6A5DFBB4283DCA8572  : public RuntimeObject
{
	int32_t ___m_taskId;
	Delegate_t* ___m_action;
	RuntimeObject* ___m_stateObject;
	TaskScheduler_t3F0550EBEF7C41F74EC8C08FF4BED0D8CE66006E* ___m_taskScheduler;
	Task_t751C4CC3ECD055BABA8A0B6A5DFBB4283DCA8572* ___m_parent;
	int32_t ___m_stateFlags;
	RuntimeObject* ___m_continuationObject;
	ContingentProperties_t3FA59480914505CEA917B1002EC675F29D0CB540* ___m_contingentProperties;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC  : public RuntimeObject
{
	AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___m_Attributes;
	int32_t ___m_AttributeCount;
	bool ___calculateNormals;
	bool ___calculateTangents;
	VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___m_Descriptors;
	RuntimeObject* ___m_Buffers;
	RuntimeObject* ___m_Logger;
};
struct VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0  : public RuntimeObject
{
	RuntimeObject* ___m_Logger;
	int32_t ___U3CUVSetCountU3Ek__BackingField;
};
struct U3CU3Ec__DisplayClass27_0_t98931B9A9F5702BFC6578F521C2F0866E10CC06D 
{
	AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___attributes;
	VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* ___U3CU3E4__this;
};
struct U3CU3Ec__DisplayClass27_0_t705F2B87E06B0436D7006CE67E66CE05E9E61926 
{
	AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___attributes;
	VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* ___U3CU3E4__this;
};
struct U3CU3Ec__DisplayClass27_0_tC9594FC1F4834B802F2F24BD00D5F4FF36F34306 
{
	AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___attributes;
	VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* ___U3CU3E4__this;
};
struct U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684 
{
	AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___attributes;
	VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* ___U3CU3E4__this;
};
struct Task_1_t824317F4B958F7512E8F7300511752937A6C6043  : public Task_t751C4CC3ECD055BABA8A0B6A5DFBB4283DCA8572
{
	bool ___m_result;
};
struct AsyncMethodBuilderCore_tD5ABB3A2536319A3345B32A5481E37E23DD8CEDF 
{
	RuntimeObject* ___m_stateMachine;
	Action_tD00B0A84D7945E50C2DFFC28EFEE6ED44ED2AD07* ___m_defaultContextAction;
};
struct AsyncMethodBuilderCore_tD5ABB3A2536319A3345B32A5481E37E23DD8CEDF_marshaled_pinvoke
{
	RuntimeObject* ___m_stateMachine;
	Il2CppMethodPointer ___m_defaultContextAction;
};
struct AsyncMethodBuilderCore_tD5ABB3A2536319A3345B32A5481E37E23DD8CEDF_marshaled_com
{
	RuntimeObject* ___m_stateMachine;
	Il2CppMethodPointer ___m_defaultContextAction;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	Il2CppChar ___m_value;
};
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 
{
	uint64_t ___jobGroup;
	int32_t ___version;
};
struct Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A 
{
	union
	{
		#pragma pack(push, tp, 1)
		struct
		{
			uint8_t ___byte_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint8_t ___byte_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_1_OffsetPadding[1];
			uint8_t ___byte_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_1_OffsetPadding_forAlignmentOnly[1];
			uint8_t ___byte_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_2_OffsetPadding[2];
			uint8_t ___byte_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_2_OffsetPadding_forAlignmentOnly[2];
			uint8_t ___byte_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_3_OffsetPadding[3];
			uint8_t ___byte_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_3_OffsetPadding_forAlignmentOnly[3];
			uint8_t ___byte_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_4_OffsetPadding[4];
			uint8_t ___byte_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_4_OffsetPadding_forAlignmentOnly[4];
			uint8_t ___byte_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_5_OffsetPadding[5];
			uint8_t ___byte_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_5_OffsetPadding_forAlignmentOnly[5];
			uint8_t ___byte_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_6_OffsetPadding[6];
			uint8_t ___byte_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_6_OffsetPadding_forAlignmentOnly[6];
			uint8_t ___byte_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_7_OffsetPadding[7];
			uint8_t ___byte_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_7_OffsetPadding_forAlignmentOnly[7];
			uint8_t ___byte_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_8_OffsetPadding[8];
			uint8_t ___byte_8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_8_OffsetPadding_forAlignmentOnly[8];
			uint8_t ___byte_8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_9_OffsetPadding[9];
			uint8_t ___byte_9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_9_OffsetPadding_forAlignmentOnly[9];
			uint8_t ___byte_9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_10_OffsetPadding[10];
			uint8_t ___byte_10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_10_OffsetPadding_forAlignmentOnly[10];
			uint8_t ___byte_10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_11_OffsetPadding[11];
			uint8_t ___byte_11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_11_OffsetPadding_forAlignmentOnly[11];
			uint8_t ___byte_11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_12_OffsetPadding[12];
			uint8_t ___byte_12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_12_OffsetPadding_forAlignmentOnly[12];
			uint8_t ___byte_12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_13_OffsetPadding[13];
			uint8_t ___byte_13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_13_OffsetPadding_forAlignmentOnly[13];
			uint8_t ___byte_13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_14_OffsetPadding[14];
			uint8_t ___byte_14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_14_OffsetPadding_forAlignmentOnly[14];
			uint8_t ___byte_14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___byte_15_OffsetPadding[15];
			uint8_t ___byte_15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___byte_15_OffsetPadding_forAlignmentOnly[15];
			uint8_t ___byte_15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int8_t ___sbyte_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int8_t ___sbyte_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_1_OffsetPadding[1];
			int8_t ___sbyte_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_1_OffsetPadding_forAlignmentOnly[1];
			int8_t ___sbyte_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_2_OffsetPadding[2];
			int8_t ___sbyte_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_2_OffsetPadding_forAlignmentOnly[2];
			int8_t ___sbyte_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_3_OffsetPadding[3];
			int8_t ___sbyte_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_3_OffsetPadding_forAlignmentOnly[3];
			int8_t ___sbyte_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_4_OffsetPadding[4];
			int8_t ___sbyte_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_4_OffsetPadding_forAlignmentOnly[4];
			int8_t ___sbyte_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_5_OffsetPadding[5];
			int8_t ___sbyte_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_5_OffsetPadding_forAlignmentOnly[5];
			int8_t ___sbyte_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_6_OffsetPadding[6];
			int8_t ___sbyte_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_6_OffsetPadding_forAlignmentOnly[6];
			int8_t ___sbyte_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_7_OffsetPadding[7];
			int8_t ___sbyte_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_7_OffsetPadding_forAlignmentOnly[7];
			int8_t ___sbyte_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_8_OffsetPadding[8];
			int8_t ___sbyte_8;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_8_OffsetPadding_forAlignmentOnly[8];
			int8_t ___sbyte_8_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_9_OffsetPadding[9];
			int8_t ___sbyte_9;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_9_OffsetPadding_forAlignmentOnly[9];
			int8_t ___sbyte_9_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_10_OffsetPadding[10];
			int8_t ___sbyte_10;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_10_OffsetPadding_forAlignmentOnly[10];
			int8_t ___sbyte_10_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_11_OffsetPadding[11];
			int8_t ___sbyte_11;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_11_OffsetPadding_forAlignmentOnly[11];
			int8_t ___sbyte_11_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_12_OffsetPadding[12];
			int8_t ___sbyte_12;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_12_OffsetPadding_forAlignmentOnly[12];
			int8_t ___sbyte_12_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_13_OffsetPadding[13];
			int8_t ___sbyte_13;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_13_OffsetPadding_forAlignmentOnly[13];
			int8_t ___sbyte_13_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_14_OffsetPadding[14];
			int8_t ___sbyte_14;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_14_OffsetPadding_forAlignmentOnly[14];
			int8_t ___sbyte_14_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___sbyte_15_OffsetPadding[15];
			int8_t ___sbyte_15;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___sbyte_15_OffsetPadding_forAlignmentOnly[15];
			int8_t ___sbyte_15_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint16_t ___uint16_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint16_t ___uint16_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_1_OffsetPadding[2];
			uint16_t ___uint16_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_1_OffsetPadding_forAlignmentOnly[2];
			uint16_t ___uint16_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_2_OffsetPadding[4];
			uint16_t ___uint16_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_2_OffsetPadding_forAlignmentOnly[4];
			uint16_t ___uint16_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_3_OffsetPadding[6];
			uint16_t ___uint16_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_3_OffsetPadding_forAlignmentOnly[6];
			uint16_t ___uint16_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_4_OffsetPadding[8];
			uint16_t ___uint16_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_4_OffsetPadding_forAlignmentOnly[8];
			uint16_t ___uint16_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_5_OffsetPadding[10];
			uint16_t ___uint16_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_5_OffsetPadding_forAlignmentOnly[10];
			uint16_t ___uint16_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_6_OffsetPadding[12];
			uint16_t ___uint16_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_6_OffsetPadding_forAlignmentOnly[12];
			uint16_t ___uint16_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint16_7_OffsetPadding[14];
			uint16_t ___uint16_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint16_7_OffsetPadding_forAlignmentOnly[14];
			uint16_t ___uint16_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int16_t ___int16_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int16_t ___int16_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_1_OffsetPadding[2];
			int16_t ___int16_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_1_OffsetPadding_forAlignmentOnly[2];
			int16_t ___int16_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_2_OffsetPadding[4];
			int16_t ___int16_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_2_OffsetPadding_forAlignmentOnly[4];
			int16_t ___int16_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_3_OffsetPadding[6];
			int16_t ___int16_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_3_OffsetPadding_forAlignmentOnly[6];
			int16_t ___int16_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_4_OffsetPadding[8];
			int16_t ___int16_4;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_4_OffsetPadding_forAlignmentOnly[8];
			int16_t ___int16_4_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_5_OffsetPadding[10];
			int16_t ___int16_5;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_5_OffsetPadding_forAlignmentOnly[10];
			int16_t ___int16_5_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_6_OffsetPadding[12];
			int16_t ___int16_6;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_6_OffsetPadding_forAlignmentOnly[12];
			int16_t ___int16_6_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int16_7_OffsetPadding[14];
			int16_t ___int16_7;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int16_7_OffsetPadding_forAlignmentOnly[14];
			int16_t ___int16_7_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint32_t ___uint32_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint32_t ___uint32_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint32_1_OffsetPadding[4];
			uint32_t ___uint32_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint32_1_OffsetPadding_forAlignmentOnly[4];
			uint32_t ___uint32_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint32_2_OffsetPadding[8];
			uint32_t ___uint32_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint32_2_OffsetPadding_forAlignmentOnly[8];
			uint32_t ___uint32_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint32_3_OffsetPadding[12];
			uint32_t ___uint32_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint32_3_OffsetPadding_forAlignmentOnly[12];
			uint32_t ___uint32_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int32_t ___int32_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int32_t ___int32_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int32_1_OffsetPadding[4];
			int32_t ___int32_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int32_1_OffsetPadding_forAlignmentOnly[4];
			int32_t ___int32_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int32_2_OffsetPadding[8];
			int32_t ___int32_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int32_2_OffsetPadding_forAlignmentOnly[8];
			int32_t ___int32_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int32_3_OffsetPadding[12];
			int32_t ___int32_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int32_3_OffsetPadding_forAlignmentOnly[12];
			int32_t ___int32_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			uint64_t ___uint64_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			uint64_t ___uint64_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___uint64_1_OffsetPadding[8];
			uint64_t ___uint64_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___uint64_1_OffsetPadding_forAlignmentOnly[8];
			uint64_t ___uint64_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			int64_t ___int64_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			int64_t ___int64_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___int64_1_OffsetPadding[8];
			int64_t ___int64_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___int64_1_OffsetPadding_forAlignmentOnly[8];
			int64_t ___int64_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			float ___single_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			float ___single_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___single_1_OffsetPadding[4];
			float ___single_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___single_1_OffsetPadding_forAlignmentOnly[4];
			float ___single_1_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___single_2_OffsetPadding[8];
			float ___single_2;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___single_2_OffsetPadding_forAlignmentOnly[8];
			float ___single_2_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___single_3_OffsetPadding[12];
			float ___single_3;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___single_3_OffsetPadding_forAlignmentOnly[12];
			float ___single_3_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			double ___double_0;
		};
		#pragma pack(pop, tp)
		struct
		{
			double ___double_0_forAlignmentOnly;
		};
		#pragma pack(push, tp, 1)
		struct
		{
			char ___double_1_OffsetPadding[8];
			double ___double_1;
		};
		#pragma pack(pop, tp)
		struct
		{
			char ___double_1_OffsetPadding_forAlignmentOnly[8];
			double ___double_1_forAlignmentOnly;
		};
	};
};
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	int8_t ___m_value;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	float ___x;
	float ___y;
	float ___z;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct float3_t7600B73F092B37F484B12910A5269F30C778D31E 
{
	float ___x;
	float ___y;
	float ___z;
};
struct float4_t545A994996126766890C1F28B43EA823F2410190 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
};
struct YieldAwaiter_t5F0A81DC85227C01FFC38D53139B5C19D920B52A 
{
	union
	{
		struct
		{
		};
		uint8_t YieldAwaiter_t5F0A81DC85227C01FFC38D53139B5C19D920B52A__padding[1];
	};
};
struct AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA 
{
	AsyncMethodBuilderCore_tD5ABB3A2536319A3345B32A5481E37E23DD8CEDF ___m_coreState;
	Task_1_t824317F4B958F7512E8F7300511752937A6C6043* ___m_task;
};
struct AsyncTaskMethodBuilder_1_t9A3ADCFF6503F4230FFD38F6C333EBCF1A034AF4 
{
	AsyncMethodBuilderCore_tD5ABB3A2536319A3345B32A5481E37E23DD8CEDF ___m_coreState;
	Task_1_tDF1FF540D7D2248A08580387A39717B7FB7A9CF9* ___m_task;
};
struct Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 
{
	bool ___hasValue;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___value;
};
struct Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
};
struct Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 
{
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A ___register;
};
struct Allocator_t996642592271AAD9EE688F142741D512C07B5824 
{
	int32_t ___value__;
};
struct Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Center;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Extents;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct GltfAccessorAttributeType_t2A3EA7ADAC3332131A4850752A6719FB131FC9F1 
{
	uint8_t ___value__;
};
struct GltfComponentType_tB7CCE9FF3B728EE7957568DA30CA8DCAC1E5CA34 
{
	int32_t ___value__;
};
struct LogCode_t75D12CD0B7E7695F8F1B0312517A7EE7C9A5E4FB 
{
	uint32_t ___value__;
};
struct MeshUpdateFlags_tCCD32DF7F112AE37CA85E45959DC6CDF64444DF6 
{
	int32_t ___value__;
};
struct NativeArrayOptions_t3E979EEF4B4840228A7692A97DA07553C6465F1D 
{
	int32_t ___value__;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct VPos_t60F9F86213E6426227874FBBA41EF5551B920A72 
{
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___position;
};
struct VPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD 
{
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___position;
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___normal;
};
struct VPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193 
{
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___position;
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___normal;
	float4_t545A994996126766890C1F28B43EA823F2410190 ___tangent;
};
struct VertexAttribute_tF34C1B76F20CA4AEC9D606BCD37A8A0C4A24C9A6 
{
	int32_t ___value__;
};
struct VertexAttributeFormat_tD714C51E671502B116ACE5E23F042BA80649D32F 
{
	int32_t ___value__;
};
struct U3CCreateVertexBufferU3Ed__20_tFDD5AE67C5D83FE33DF820C3C9ED617BF88FF2BF 
{
	int32_t ___U3CU3E1__state;
	AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA ___U3CU3Et__builder;
	VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* ___U3CU3E4__this;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 ___U3CjhU3E5__2;
	YieldAwaiter_t5F0A81DC85227C01FFC38D53139B5C19D920B52A ___U3CU3Eu__1;
};
struct U3CCreateVertexBufferU3Ed__20_tDADD490A251616C2620B0CB2C503DFC0198E7D6A 
{
	int32_t ___U3CU3E1__state;
	AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA ___U3CU3Et__builder;
	VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* ___U3CU3E4__this;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 ___U3CjhU3E5__2;
	YieldAwaiter_t5F0A81DC85227C01FFC38D53139B5C19D920B52A ___U3CU3Eu__1;
};
struct U3CCreateVertexBufferU3Ed__20_t498F74500406EE05901BC1C3ED2CDD59B394793A 
{
	int32_t ___U3CU3E1__state;
	AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA ___U3CU3Et__builder;
	VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* ___U3CU3E4__this;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 ___U3CjhU3E5__2;
	YieldAwaiter_t5F0A81DC85227C01FFC38D53139B5C19D920B52A ___U3CU3Eu__1;
};
struct U3CCreateVertexBufferU3Ed__20_tCC7730169CE74300C548BDF2435F4F8FA2BCCA51 
{
	int32_t ___U3CU3E1__state;
	AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA ___U3CU3Et__builder;
	VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* ___U3CU3E4__this;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 ___U3CjhU3E5__2;
	YieldAwaiter_t5F0A81DC85227C01FFC38D53139B5C19D920B52A ___U3CU3Eu__1;
};
struct NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t15E6E9438E5B73A5BFCFCADFEBF1D3D8949C6858 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct NativeArray_1_t38B974FEBDE9C6BC682E4154FA808DE4F13EF788 
{
	void* ___m_Buffer;
	int32_t ___m_Length;
	int32_t ___m_AllocatorLabel;
};
struct Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F 
{
	bool ___hasValue;
	Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 ___value;
};
struct VectorSizeHelper_tAB183E4966E0B97A19A75D213EDAE51037A6BF3C 
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ____placeholder;
	uint8_t ____byte;
};
struct AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E  : public NamedObject_t907D3C13C4675E1432B946C6306227637A38EA9D
{
	int32_t ___bufferView;
	int32_t ___byteOffset;
	int32_t ___componentType;
	bool ___normalized;
	int32_t ___count;
	String_t* ___type;
	uint8_t ___m_TypeEnum;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___max;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___min;
};
struct AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6  : public RuntimeObject
{
	uint32_t ___bufferView;
	int32_t ___byteOffset;
	int32_t ___componentType;
};
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 
{
	int32_t ___U3CattributeU3Ek__BackingField;
	int32_t ___U3CformatU3Ek__BackingField;
	int32_t ___U3CdimensionU3Ek__BackingField;
	int32_t ___U3CstreamU3Ek__BackingField;
};
struct VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B  : public VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC
{
	NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 ___m_Data;
	bool ___m_HasNormals;
	bool ___m_HasTangents;
	bool ___m_HasColors;
	bool ___m_HasBones;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* ___m_TexCoords;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* ___m_Colors;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* ___m_Bones;
	AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* ___m_PositionAccessors;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___U3CVertexIntervalsU3Ek__BackingField;
};
struct VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA  : public VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC
{
	NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E ___m_Data;
	bool ___m_HasNormals;
	bool ___m_HasTangents;
	bool ___m_HasColors;
	bool ___m_HasBones;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* ___m_TexCoords;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* ___m_Colors;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* ___m_Bones;
	AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* ___m_PositionAccessors;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___U3CVertexIntervalsU3Ek__BackingField;
};
struct VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A  : public VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC
{
	NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 ___m_Data;
	bool ___m_HasNormals;
	bool ___m_HasTangents;
	bool ___m_HasColors;
	bool ___m_HasBones;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* ___m_TexCoords;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* ___m_Colors;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* ___m_Bones;
	AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* ___m_PositionAccessors;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___U3CVertexIntervalsU3Ek__BackingField;
};
struct VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0  : public VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC
{
	NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___m_Data;
	bool ___m_HasNormals;
	bool ___m_HasTangents;
	bool ___m_HasColors;
	bool ___m_HasBones;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* ___m_TexCoords;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* ___m_Colors;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* ___m_Bones;
	AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* ___m_PositionAccessors;
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___U3CVertexIntervalsU3Ek__BackingField;
};
struct VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t6C4A7357B053718CE61F4EED5DAEB50002965313 ___m_Data;
};
struct VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_tB2C1C169B592627CDAF43F7E5E024063D054AD5B ___m_Data;
};
struct VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t9AA7FFA5949BEEFDB7B9A1480D3E34A57949C997 ___m_Data;
};
struct VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t28DB358486749485CE38C5A4EA2385D17C20EDA8 ___m_Data;
};
struct VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t404BBFB2BC94AA9EAE4427EE21EC40EDDB226DBA ___m_Data;
};
struct VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_tC7BE63B4F71DAE1ACB75473D6FB9B945C9EED27E ___m_Data;
};
struct VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_tF85EF2100A75F9A7EF15F7779782D710E4792172 ___m_Data;
};
struct VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595  : public VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0
{
	NativeArray_1_t8B61B6B04E69AE197639FB5BAC90AF8C96922827 ___m_Data;
};
struct IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94  : public RuntimeObject
{
	RuntimeObject* ___m_Logger;
	NativeArray_1_t15E6E9438E5B73A5BFCFCADFEBF1D3D8949C6858 ___m_Data;
};
struct VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA  : public RuntimeObject
{
	RuntimeObject* ___m_Logger;
	NativeArray_1_t38B974FEBDE9C6BC682E4154FA808DE4F13EF788 ___m_Data;
};
struct EmptyArray_1_tF2F83411E5DC963DBFFD1F75B10B58A1ED224DD5_StaticFields
{
	__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* ___Value;
};
struct CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticFields
{
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___invariant_culture_info;
	RuntimeObject* ___shared_table_lock;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___default_current_culture;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_DefaultThreadCurrentUICulture;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_DefaultThreadCurrentCulture;
	Dictionary_2_t9FA6D82CAFC18769F7515BB51D1C56DAE09381C3* ___shared_by_number;
	Dictionary_2_tE1603CE612C16451D1E56FF4D4859D4FE4087C28* ___shared_by_name;
	CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* ___s_UserPreferredCultureInfoInAppX;
	bool ___IsTaiwanSku;
};
struct NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472_StaticFields
{
	NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* ___invariantInfo;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Task_1_t824317F4B958F7512E8F7300511752937A6C6043_StaticFields
{
	TaskFactory_1_tFAEAC22A1E986463E6956C344A78A7C7197288E0* ___s_defaultFactory;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1;
};
struct float3_t7600B73F092B37F484B12910A5269F30C778D31E_StaticFields
{
	float3_t7600B73F092B37F484B12910A5269F30C778D31E ___zero;
};
struct float4_t545A994996126766890C1F28B43EA823F2410190_StaticFields
{
	float4_t545A994996126766890C1F28B43EA823F2410190 ___zero;
};
struct AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_StaticFields
{
	Task_1_t824317F4B958F7512E8F7300511752937A6C6043* ___s_defaultResultTask;
};
struct AsyncTaskMethodBuilder_1_t9A3ADCFF6503F4230FFD38F6C333EBCF1A034AF4_StaticFields
{
	Task_1_tDF1FF540D7D2248A08580387A39717B7FB7A9CF9* ___s_defaultResultTask;
};
struct Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A_StaticFields
{
	int32_t ___s_count;
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___s_zero;
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___s_one;
	Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A ___s_allOnes;
};
struct Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields
{
	int32_t ___s_count;
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___s_zero;
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___s_one;
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___s_allOnes;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322  : public RuntimeArray
{
	ALIGN_FIELD (8) Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* m_Items[1];

	inline Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A  : public RuntimeArray
{
	ALIGN_FIELD (8) AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* m_Items[1];

	inline AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2  : public RuntimeArray
{
	ALIGN_FIELD (8) VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 m_Items[1];

	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 value)
	{
		m_Items[index] = value;
	}
};
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppSharedGenericObject* m_Items[1];

	inline Il2CppSharedGenericObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Il2CppSharedGenericObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppSharedGenericObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppSharedGenericObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_fshared_inline (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_other, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, void* ___0_dataPointer, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AsyncTaskMethodBuilder_1_t9A3ADCFF6503F4230FFD38F6C333EBCF1A034AF4 AsyncTaskMethodBuilder_1_Create_m852C283F3EAD7381A0CC8D14204899C192BDC20A_fshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsyncTaskMethodBuilder_1_Start_TisU3CCreateVertexBufferU3Ed__20_tFDD5AE67C5D83FE33DF820C3C9ED617BF88FF2BF_mCD2D27028557929EA4186A5F6B77E94149D125D5 (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* __this, U3CCreateVertexBufferU3Ed__20_tFDD5AE67C5D83FE33DF820C3C9ED617BF88FF2BF* ___0_stateMachine, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t824317F4B958F7512E8F7300511752937A6C6043* AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943 (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mBA83AAC5DEEF6A424E816BC22A562F9F16331060 (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_nativeArray, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_gshared_inline (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0 (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1 (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9 (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333 (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5 (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19 (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016 (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 NativeArray_1_GetSubArray_mA9C8FA837D0A861E42C28E31C02AF86688C0801E (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_mFB6B5196F674BE1200C6428109149A88F30003A7 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526 (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_mE649B0A6DF480A7F1F6FEBF94F3EAE40DEEB4429_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_i, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_handle, U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684* ___2_p, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mDB8D148A0EF2CE914022B139EDC228BC42BA980D (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m6BDF1E860A988B4B255D8FDF639C0C4D8B2FA788 (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsyncTaskMethodBuilder_1_Start_TisU3CCreateVertexBufferU3Ed__20_tDADD490A251616C2620B0CB2C503DFC0198E7D6A_mCDF95461FA64637CA4378B4284931B452FB943CB (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* __this, U3CCreateVertexBufferU3Ed__20_tDADD490A251616C2620B0CB2C503DFC0198E7D6A* ___0_stateMachine, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m6ED28625050D6187E9FF635F2F0B84FAE98963DE (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m2846F0D611AC1AF6D33E17DF9FC1F7F4AF44188F (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_m98F5B919E464DF0F3ACD4366F3DC57AF2454635E (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mF28F15854DB63F91A8E4ECE7E7046833DEECD545 (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsyncTaskMethodBuilder_1_Start_TisU3CCreateVertexBufferU3Ed__20_t498F74500406EE05901BC1C3ED2CDD59B394793A_mA70E4D00EB60036D398D673AEB15EE6D8F0A6D6F (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* __this, U3CCreateVertexBufferU3Ed__20_t498F74500406EE05901BC1C3ED2CDD59B394793A* ___0_stateMachine, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mB26D6A63E8B3F18A77A5552D357236D2292DDC4B (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m409E88D135C578E00B0B9829877F8264B12C9F68 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m5C4B829BA2A5130FB5C09B29AD8805155EA7C756 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m82995B1021A45DA3ADE8B42EB36038FBB092EEAF (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m6578702C98214F7F52425ADD0766109D2BE9953B_inline (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 Nullable_1_get_Value_mC79E0A8A7D9E70CC7ABA0073EF626DE21DFADADB (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1_fshared (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73 (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* SR_Format_m9E8DC9AEFDC34AC67473EFAEAB78C5066C1A0D09 (String_t* ___0_resourceFormat, RuntimeObject* ___1_p1, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IndexOutOfRangeException__ctor_mFD06819F05B815BE2D6E826D4E04F4C449D0A425 (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* __this, String_t* ___0_message, const RuntimeMethod* method) ;
inline bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_inline (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	return ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, RuntimeObject*, const RuntimeMethod*))Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_fshared_inline)(__this, ___0_obj, method);
}
inline bool Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8 (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_other, const RuntimeMethod* method)
{
	return ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8_fshared)(__this, ___0_other, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678 (uint8_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7 (int32_t ___0_h1, int32_t ___1_h2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF (int8_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200 (uint16_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1 (int16_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC (uint32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92 (uint64_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int64_GetHashCode_mDB050BE2AC244D92B14D1DF725AAD279CDC48496 (int64_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2 (float* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline (double* __this, const RuntimeMethod* method) ;
inline int32_t Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, const RuntimeMethod*))Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* CultureInfo_get_CurrentCulture_m8A4580F49DDD7E9DB34C699965423DB8E3BBA9A5 (const RuntimeMethod* method) ;
inline String_t* Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method)
{
	return ((  String_t* (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, const RuntimeMethod*))Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D (StringBuilder_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* NumberFormatInfo_GetInstance_m705987E5E7D3E5EC5C5DD2D088FBC9BCBA0FC31F (RuntimeObject* ___0_formatProvider, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline (NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1 (StringBuilder_t* __this, Il2CppChar ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringBuilder_t* StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D (StringBuilder_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
inline String_t* Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method)
{
	return ((  String_t* (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, String_t*, RuntimeObject*, const RuntimeMethod*))Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F_fshared)(__this, ___0_format, ___1_formatProvider, method);
}
inline void Vector_1__ctor_mEA86543744A54FCE590FDBF012FAE9037A5F1606 (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A*, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*, const RuntimeMethod*))Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared)(__this, ___0_existingRegister, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline (const RuntimeMethod* method) ;
inline void Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001 (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, void* ___0_dataPointer, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, void*, const RuntimeMethod*))Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001_fshared)(__this, ___0_dataPointer, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int8_t ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int16_t ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline (const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline (const RuntimeMethod* method) ;
inline void Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674 (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*, const RuntimeMethod*))Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared)(__this, ___0_existingRegister, method);
}
inline void Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2 (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method)
{
	((  void (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Il2CppFullySharedGenericStruct, const RuntimeMethod*))Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2_fshared)((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*)__this, ___0_value, method);
}
inline AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA AsyncTaskMethodBuilder_1_Create_mA86694527610A40A01A943B16F0ECDDD8F00982D (const RuntimeMethod* method)
{
	return ((  AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA (*) (const RuntimeMethod*))AsyncTaskMethodBuilder_1_Create_m852C283F3EAD7381A0CC8D14204899C192BDC20A_fshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsyncTaskMethodBuilder_1_Start_TisU3CCreateVertexBufferU3Ed__20_tFDD5AE67C5D83FE33DF820C3C9ED617BF88FF2BF_mCD2D27028557929EA4186A5F6B77E94149D125D5 (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* __this, U3CCreateVertexBufferU3Ed__20_tFDD5AE67C5D83FE33DF820C3C9ED617BF88FF2BF* ___0_stateMachine, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t824317F4B958F7512E8F7300511752937A6C6043* AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943 (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mBA83AAC5DEEF6A424E816BC22A562F9F16331060 (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_m330509F7AC793C43640F0649AC22729C08D9A935_inline (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7 (Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* __this, const RuntimeMethod* method) ;
inline StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline (const RuntimeMethod* method)
{
	return ((  StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* (*) (const RuntimeMethod*))Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_gshared_inline)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0 (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1 (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9 (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333 (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5 (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19 (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016 (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* __this, int32_t ___0_uvSetCount, int32_t ___1_vertexCount, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, int32_t ___0_vertexCount, RuntimeObject* ___1_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, int32_t ___0_vertexCount, RuntimeObject* ___1_logger, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17 (AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7 (Type_t* ___0_t, const RuntimeMethod* method) ;
inline bool VertexBufferGenerator_1_SchedulePositionsJobs_mF6C412F9AE54E68C390D715FD61E39EA0B1104C1 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, int32_t, uint8_t*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared)(__this, ___0_i, ___1_vDataPtr, ___2_outputByteStride, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleNormalsJobs_m759C2CDD45A3A7E6BBB0FFE983E33A6E7D248136 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleTangentsJobs_m4D2957E9D254DF24797C4572CAE523501105225D (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m5B614A1018475BC3C9AE872EBB9E1AF42273AF7B (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  int32_t (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared)(__this, ___0_att, ___1_uvSetCount, ___2_i, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleColorsJobs_mB67927A5E7B9EB64C6BDCE399C0C3FED1243331A (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared)(__this, ___0_att, ___1_i, ___2_handles, ___3_handleIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 NativeArray_1_GetSubArray_mA9C8FA837D0A861E42C28E31C02AF86688C0801E (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, int32_t ___0_start, int32_t ___1_length, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_mFB6B5196F674BE1200C6428109149A88F30003A7 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___0_jobs, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A (NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526 (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_value, const RuntimeMethod* method) ;
inline bool VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_m30D6D89C36F1308DC8C04906CDC86F9F312F885C (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, int32_t ___0_i, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_handle, U3CU3Ec__DisplayClass27_0_t98931B9A9F5702BFC6578F521C2F0866E10CC06D* ___2_p, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, int32_t, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, U3CU3Ec__DisplayClass27_0_t98931B9A9F5702BFC6578F521C2F0866E10CC06D*, const RuntimeMethod*))VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_mE649B0A6DF480A7F1F6FEBF94F3EAE40DEEB4429_fshared)(__this, ___0_i, ___1_handle, ___2_p, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 VertexBufferBones_ScheduleSortAndNormalizeBoneWeightsJob_mD358C4D61558BCB09ACFD05E2D32014CAD205835 (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 ___0_dependsOn, const RuntimeMethod* method) ;
inline void VertexBufferGenerator_1_CreateDescriptors_m61EB63159D587C7438A2610FCEA2BA5E5AD603A7 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, const RuntimeMethod* method)
{
	((  void (*) (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B*, const RuntimeMethod*))VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, int32_t ___0_vertexCount, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___1_attributes, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mDB8D148A0EF2CE914022B139EDC228BC42BA980D (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198 (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799 (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_stream, int32_t ___2_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_m6492C57B05D6B9FFD26772B944B2A6BEF6015483_inline (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m6BDF1E860A988B4B255D8FDF639C0C4D8B2FA788 (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163 (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04 (VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsyncTaskMethodBuilder_1_Start_TisU3CCreateVertexBufferU3Ed__20_tDADD490A251616C2620B0CB2C503DFC0198E7D6A_mCDF95461FA64637CA4378B4284931B452FB943CB (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* __this, U3CCreateVertexBufferU3Ed__20_tDADD490A251616C2620B0CB2C503DFC0198E7D6A* ___0_stateMachine, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_m6ED28625050D6187E9FF635F2F0B84FAE98963DE (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mEF24F47840037840AEF8626D31E8C4C54CEF3340_inline (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline bool VertexBufferGenerator_1_SchedulePositionsJobs_m7E7DCC6FDC1062FD769A6CE944BA2574F74354AC (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, int32_t, uint8_t*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared)(__this, ___0_i, ___1_vDataPtr, ___2_outputByteStride, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleNormalsJobs_m4A6BA6C3D0065FCE7DEBA556830D0BB2C20F1050 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleTangentsJobs_m24ED9C3178F6780CE23AF897AEE13B9F83A4E24B (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m5B1B735D20E1FBF67AA5DE4CE83BAC26C59C0A61 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  int32_t (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared)(__this, ___0_att, ___1_uvSetCount, ___2_i, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleColorsJobs_mC44D082A9C89E72CA01C5D92DE0918F1CADD2304 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared)(__this, ___0_att, ___1_i, ___2_handles, ___3_handleIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m2846F0D611AC1AF6D33E17DF9FC1F7F4AF44188F (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) ;
inline bool VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_m6A1872C9E568642666DA85D454871742EB7A9B7E (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, int32_t ___0_i, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_handle, U3CU3Ec__DisplayClass27_0_t705F2B87E06B0436D7006CE67E66CE05E9E61926* ___2_p, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, int32_t, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, U3CU3Ec__DisplayClass27_0_t705F2B87E06B0436D7006CE67E66CE05E9E61926*, const RuntimeMethod*))VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_mE649B0A6DF480A7F1F6FEBF94F3EAE40DEEB4429_fshared)(__this, ___0_i, ___1_handle, ___2_p, method);
}
inline void VertexBufferGenerator_1_CreateDescriptors_m6543578CB5017D6DE58830F12C0B02C149D77C17 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, const RuntimeMethod* method)
{
	((  void (*) (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA*, const RuntimeMethod*))VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_m98F5B919E464DF0F3ACD4366F3DC57AF2454635E (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_mF889FB0A50008701DFF815D51811D6C2FA88D506_inline (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_mF28F15854DB63F91A8E4ECE7E7046833DEECD545 (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AsyncTaskMethodBuilder_1_Start_TisU3CCreateVertexBufferU3Ed__20_t498F74500406EE05901BC1C3ED2CDD59B394793A_mA70E4D00EB60036D398D673AEB15EE6D8F0A6D6F (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* __this, U3CCreateVertexBufferU3Ed__20_t498F74500406EE05901BC1C3ED2CDD59B394793A* ___0_stateMachine, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1__ctor_mB26D6A63E8B3F18A77A5552D357236D2292DDC4B (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method) ;
inline void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m4DFB73460B0763281BB179BE6CB139906474F02E_inline (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 ___0_nativeArray, const RuntimeMethod* method)
{
	return ((  void* (*) (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250, const RuntimeMethod*))NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline)(___0_nativeArray, method);
}
inline bool VertexBufferGenerator_1_SchedulePositionsJobs_mA272F8DC9995E815EDD688721170775AE5283213 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, int32_t, uint8_t*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared)(__this, ___0_i, ___1_vDataPtr, ___2_outputByteStride, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleNormalsJobs_mDF628CAC3BCB5DEDB2AE0FCE853E7DC2FE3C621A (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleTangentsJobs_m71316553C3BA7A0DD23BBBA9A82FA54D674587FB (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared)(__this, ___0_att, ___1_vDataPtr, ___2_outputByteStride, ___3_i, ___4_handles, ___5_handleIndex, method);
}
inline int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m0F6AC8EC930129564B6EF188169ED570B9566729 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method)
{
	return ((  int32_t (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared)(__this, ___0_att, ___1_uvSetCount, ___2_i, ___3_handles, ___4_handleIndex, method);
}
inline bool VertexBufferGenerator_1_ScheduleColorsJobs_m2704633CCB9A2628480745DE8991303651C6D68F (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared)(__this, ___0_att, ___1_i, ___2_handles, ___3_handleIndex, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m409E88D135C578E00B0B9829877F8264B12C9F68 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) ;
inline bool VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_m96169F75DA19FF2E0BEDB35946C45D7A19949611 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, int32_t ___0_i, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_handle, U3CU3Ec__DisplayClass27_0_tC9594FC1F4834B802F2F24BD00D5F4FF36F34306* ___2_p, const RuntimeMethod* method)
{
	return ((  bool (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, int32_t, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, U3CU3Ec__DisplayClass27_0_tC9594FC1F4834B802F2F24BD00D5F4FF36F34306*, const RuntimeMethod*))VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_mE649B0A6DF480A7F1F6FEBF94F3EAE40DEEB4429_fshared)(__this, ___0_i, ___1_handle, ___2_p, method);
}
inline void VertexBufferGenerator_1_CreateDescriptors_m615516608A7DCDC74BE1B06896D86163FB7D9173 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, const RuntimeMethod* method)
{
	((  void (*) (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A*, const RuntimeMethod*))VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Mesh_SetVertexBufferData_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m5C4B829BA2A5130FB5C09B29AD8805155EA7C756 (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* __this, NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 ___0_data, int32_t ___1_dataStart, int32_t ___2_meshBufferStart, int32_t ___3_count, int32_t ___4_stream, int32_t ___5_flags, const RuntimeMethod* method) ;
inline bool NativeArray_1_get_IsCreated_mC5ED66430AE33CD749E7A37DF7B48DFB49976CC7_inline (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*, const RuntimeMethod*))NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NativeArray_1_Dispose_m82995B1021A45DA3ADE8B42EB36038FBB092EEAF (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F AccessorBase_TryGetBounds_mE38F5405047CC52A32D7E623A022F15BC041172F (AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m6578702C98214F7F52425ADD0766109D2BE9953B_inline (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 Nullable_1_get_Value_mC79E0A8A7D9E70CC7ABA0073EF626DE21DFADADB (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGeneratorBase__ctor_m8AE7BE0A5AA98BD3B83C9DF388451E5EA6DDCCF2 (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC* __this, int32_t ___0_primitiveCount, RuntimeObject* ___1_buffers, RuntimeObject* ___2_logger, const RuntimeMethod* method) ;
inline void NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1 (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, int32_t ___0_length, int32_t ___1_allocator, int32_t ___2_options, const RuntimeMethod* method)
{
	((  void (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, int32_t, int32_t, int32_t, const RuntimeMethod*))NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1_fshared)(__this, ___0_length, ___1_allocator, ___2_options, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGeneratorBase_GetVector3Job_m927290C4C47D6AC7254AE09C0DA34D29321E7042 (RuntimeObject* ___0_buffers, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* ___1_accessor, float3_t7600B73F092B37F484B12910A5269F30C778D31E* ___2_output, int32_t ___3_outputByteStride, bool ___4_normalized, bool ___5_ensureUnitLength, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGeneratorBase_GetVector3SparseJob_m40E689FD8B2D5E53344AA7C5F2F77B8025127D3B (void* ___0_indexBuffer, void* ___1_valueBuffer, int32_t ___2_sparseCount, int32_t ___3_indexType, int32_t ___4_valueType, float3_t7600B73F092B37F484B12910A5269F30C778D31E* ___5_output, int32_t ___6_outputByteStride, Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* ___7_dependsOn, bool ___8_normalized, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73 (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGeneratorBase_GetTangentsJob_mA4F2AA421F08AF0793274A4BEB952FB29D96C3C3 (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC* __this, void* ___0_input, int32_t ___1_count, int32_t ___2_inputType, int32_t ___3_inputByteStride, float4_t545A994996126766890C1F28B43EA823F2410190* ___4_output, int32_t ___5_outputByteStride, bool ___6_normalized, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Attributes_TryGetAllUVAccessors_m30F2F2BCFC23CC3184624E1B24885C7C1D3AD90E (Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C** ___0_uvAccessors, bool* ___1_limitExceeded, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferColors_ScheduleVertexColorJob_m04DB2B7BE59977BB358A9AF4EAC4B501ACEB3CF8 (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, int32_t ___0_colorAccessorIndex, int32_t ___1_offset, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, RuntimeObject* ___3_buffers, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline (VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexAttributeDescriptor__ctor_m713B31395FB13FDEB2665F5C4C31572D5875A43A (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76* __this, int32_t ___0_attribute, int32_t ___1_format, int32_t ___2_dimension, int32_t ___3_stream, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferColors_AddDescriptors_m9044A5AA91D41DB1C2C11F9C4F2CD96EACA72277 (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* __this, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_dst, int32_t ___1_offset, int32_t ___2_stream, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferBones_AddDescriptors_mC6CB82E330C72295F0EBB23137C4BB088313E358 (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* ___0_dst, int32_t ___1_offset, int32_t ___2_stream, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferBones_ScheduleVertexBonesJob_m22A29825D18AF2F4DF85CAB97E2DDBB3482F6940 (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* __this, int32_t ___0_weightsAccessorIndex, int32_t ___1_jointsAccessorIndex, int32_t ___2_offset, RuntimeObject* ___3_buffers, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t BitConverter_DoubleToInt64Bits_m4F42741818550F9956B5FBAF88C051F4DE5B0AE6_inline (double ___0_value, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 8055
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_get_Count_m3432B49FF8435F45396666AA8B4724CF478EC0A1_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_0 = ((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count;
		return L_0;
	}
}
// Method Definition Index: 8056
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 Vector_1_get_Zero_m3384DC19FF560B5C07194EB2690C6AE65E910311_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_0 = ((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero;
		return L_0;
	}
}
// Method Definition Index: 8057
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_InitializeCount_m504CE8338E1C01BCEFF3CBA1A65D3F27AB0D6E93_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	//<source_info:<no-source>:1>
	VectorSizeHelper_tAB183E4966E0B97A19A75D213EDAE51037A6BF3C V_0;
	memset((&V_0), 0, sizeof(V_0));
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int32_t G_B2_0 = 0;
	int32_t G_B1_0 = 0;
	int32_t G_B21_0 = 0;
	int32_t G_B4_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B5_0 = 0;
	int32_t G_B8_0 = 0;
	int32_t G_B7_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B9_0 = 0;
	int32_t G_B12_0 = 0;
	int32_t G_B11_0 = 0;
	int32_t G_B14_0 = 0;
	int32_t G_B13_0 = 0;
	int32_t G_B16_0 = 0;
	int32_t G_B15_0 = 0;
	int32_t G_B18_0 = 0;
	int32_t G_B17_0 = 0;
	int32_t G_B20_0 = 0;
	int32_t G_B19_0 = 0;
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* L_0 = (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*)(&(&V_0)->____placeholder);
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_1 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&L_0->___register);
		uint8_t* L_2 = (uint8_t*)(&L_1->___byte_0);
		uintptr_t L_3 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_2,NULL));
		V_1 = (uint8_t*)L_3;
		uint8_t* L_4 = (uint8_t*)(&(&V_0)->____byte);
		uintptr_t L_5 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_4,NULL));
		uint8_t* L_6 = V_1;
		int64_t L_7 = (il2cpp_codegen_conv<int64_t,uint8_t*,intptr_t,false,false>(((uint8_t*)((intptr_t)((uint8_t*)il2cpp_codegen_subtract((intptr_t)L_5, (intptr_t)L_6))/1)),NULL));
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(L_7,NULL));
		V_2 = (-1);
		bool L_9 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_9)
		{
			G_B2_0 = L_8;
			goto IL_0045;
		}
		G_B1_0 = L_8;
	}
	{
		V_2 = 1;
		G_B21_0 = G_B1_0;
		goto IL_0176;
	}

IL_0045:
	{
		bool L_10 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_10)
		{
			G_B4_0 = G_B2_0;
			goto IL_0067;
		}
		G_B3_0 = G_B2_0;
	}
	{
		V_2 = 1;
		G_B21_0 = G_B3_0;
		goto IL_0176;
	}

IL_0067:
	{
		bool L_11 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_11)
		{
			G_B6_0 = G_B4_0;
			goto IL_0089;
		}
		G_B5_0 = G_B4_0;
	}
	{
		V_2 = 2;
		G_B21_0 = G_B5_0;
		goto IL_0176;
	}

IL_0089:
	{
		bool L_12 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_12)
		{
			G_B8_0 = G_B6_0;
			goto IL_00ab;
		}
		G_B7_0 = G_B6_0;
	}
	{
		V_2 = 2;
		G_B21_0 = G_B7_0;
		goto IL_0176;
	}

IL_00ab:
	{
		bool L_13 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_13)
		{
			G_B10_0 = G_B8_0;
			goto IL_00cd;
		}
		G_B9_0 = G_B8_0;
	}
	{
		V_2 = 4;
		G_B21_0 = G_B9_0;
		goto IL_0176;
	}

IL_00cd:
	{
		bool L_14 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_14)
		{
			G_B12_0 = G_B10_0;
			goto IL_00ef;
		}
		G_B11_0 = G_B10_0;
	}
	{
		V_2 = 4;
		G_B21_0 = G_B11_0;
		goto IL_0176;
	}

IL_00ef:
	{
		bool L_15 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_15)
		{
			G_B14_0 = G_B12_0;
			goto IL_010e;
		}
		G_B13_0 = G_B12_0;
	}
	{
		V_2 = 8;
		G_B21_0 = G_B13_0;
		goto IL_0176;
	}

IL_010e:
	{
		bool L_16 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_16)
		{
			G_B16_0 = G_B14_0;
			goto IL_012d;
		}
		G_B15_0 = G_B14_0;
	}
	{
		V_2 = 8;
		G_B21_0 = G_B15_0;
		goto IL_0176;
	}

IL_012d:
	{
		bool L_17 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_17)
		{
			G_B18_0 = G_B16_0;
			goto IL_014c;
		}
		G_B17_0 = G_B16_0;
	}
	{
		V_2 = 4;
		G_B21_0 = G_B17_0;
		goto IL_0176;
	}

IL_014c:
	{
		bool L_18 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_18)
		{
			G_B20_0 = G_B18_0;
			goto IL_016b;
		}
		G_B19_0 = G_B18_0;
	}
	{
		V_2 = 8;
		G_B21_0 = G_B19_0;
		goto IL_0176;
	}

IL_016b:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_19 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_19, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_19, method);
	}

IL_0176:
	{
		int32_t L_20 = V_2;
		return ((int32_t)(G_B21_0/L_20));
	}
}
// Method Definition Index: 8058
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Il2CppFullySharedGenericStruct ___0_value, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const Il2CppFullySharedGenericStruct L_8 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_21 = L_8;
	const Il2CppFullySharedGenericStruct L_35 = L_8;
	const Il2CppFullySharedGenericStruct L_49 = L_8;
	const Il2CppFullySharedGenericStruct L_63 = L_8;
	const Il2CppFullySharedGenericStruct L_77 = L_8;
	const Il2CppFullySharedGenericStruct L_91 = L_8;
	const Il2CppFullySharedGenericStruct L_105 = L_8;
	const Il2CppFullySharedGenericStruct L_119 = L_8;
	const Il2CppFullySharedGenericStruct L_133 = L_8;
	const Il2CppFullySharedGenericStruct L_141 = L_8;
	const Il2CppFullySharedGenericStruct L_190 = L_8;
	const Il2CppFullySharedGenericStruct L_239 = L_8;
	const Il2CppFullySharedGenericStruct L_264 = L_8;
	const Il2CppFullySharedGenericStruct L_289 = L_8;
	const Il2CppFullySharedGenericStruct L_302 = L_8;
	const Il2CppFullySharedGenericStruct L_315 = L_8;
	const Il2CppFullySharedGenericStruct L_322 = L_8;
	const Il2CppFullySharedGenericStruct L_329 = L_8;
	const Il2CppFullySharedGenericStruct L_342 = L_8;
	const Il2CppFullySharedGenericStruct L_144 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_193 = L_144;
	const Il2CppFullySharedGenericStruct L_242 = L_144;
	const Il2CppFullySharedGenericStruct L_267 = L_144;
	const Il2CppFullySharedGenericStruct L_292 = L_144;
	const Il2CppFullySharedGenericStruct L_305 = L_144;
	const Il2CppFullySharedGenericStruct L_318 = L_144;
	const Il2CppFullySharedGenericStruct L_325 = L_144;
	const Il2CppFullySharedGenericStruct L_332 = L_144;
	const Il2CppFullySharedGenericStruct L_345 = L_144;
	const Il2CppFullySharedGenericStruct L_147 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_196 = L_147;
	const Il2CppFullySharedGenericStruct L_245 = L_147;
	const Il2CppFullySharedGenericStruct L_270 = L_147;
	const Il2CppFullySharedGenericStruct L_295 = L_147;
	const Il2CppFullySharedGenericStruct L_308 = L_147;
	const Il2CppFullySharedGenericStruct L_335 = L_147;
	const Il2CppFullySharedGenericStruct L_150 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_199 = L_150;
	const Il2CppFullySharedGenericStruct L_248 = L_150;
	const Il2CppFullySharedGenericStruct L_273 = L_150;
	const Il2CppFullySharedGenericStruct L_298 = L_150;
	const Il2CppFullySharedGenericStruct L_311 = L_150;
	const Il2CppFullySharedGenericStruct L_338 = L_150;
	const Il2CppFullySharedGenericStruct L_153 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_202 = L_153;
	const Il2CppFullySharedGenericStruct L_251 = L_153;
	const Il2CppFullySharedGenericStruct L_276 = L_153;
	const Il2CppFullySharedGenericStruct L_156 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_205 = L_156;
	const Il2CppFullySharedGenericStruct L_254 = L_156;
	const Il2CppFullySharedGenericStruct L_279 = L_156;
	const Il2CppFullySharedGenericStruct L_159 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_208 = L_159;
	const Il2CppFullySharedGenericStruct L_257 = L_159;
	const Il2CppFullySharedGenericStruct L_282 = L_159;
	const Il2CppFullySharedGenericStruct L_162 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_211 = L_162;
	const Il2CppFullySharedGenericStruct L_260 = L_162;
	const Il2CppFullySharedGenericStruct L_285 = L_162;
	const Il2CppFullySharedGenericStruct L_165 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_214 = L_165;
	const Il2CppFullySharedGenericStruct L_168 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_217 = L_168;
	const Il2CppFullySharedGenericStruct L_171 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_220 = L_171;
	const Il2CppFullySharedGenericStruct L_174 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_223 = L_174;
	const Il2CppFullySharedGenericStruct L_177 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_226 = L_177;
	const Il2CppFullySharedGenericStruct L_180 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_229 = L_180;
	const Il2CppFullySharedGenericStruct L_183 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_232 = L_183;
	const Il2CppFullySharedGenericStruct L_186 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_235 = L_186;
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	int32_t V_2 = 0;
	int8_t* V_3 = NULL;
	int8_t* V_4 = NULL;
	int32_t V_5 = 0;
	uint16_t* V_6 = NULL;
	uint16_t* V_7 = NULL;
	int32_t V_8 = 0;
	int16_t* V_9 = NULL;
	int16_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint32_t* V_12 = NULL;
	uint32_t* V_13 = NULL;
	int32_t V_14 = 0;
	int32_t* V_15 = NULL;
	int32_t* V_16 = NULL;
	int32_t V_17 = 0;
	uint64_t* V_18 = NULL;
	uint64_t* V_19 = NULL;
	int32_t V_20 = 0;
	int64_t* V_21 = NULL;
	int64_t* V_22 = NULL;
	int32_t V_23 = 0;
	float* V_24 = NULL;
	float* V_25 = NULL;
	int32_t V_26 = 0;
	double* V_27 = NULL;
	double* V_28 = NULL;
	int32_t V_29 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2));
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0386;
		}
	}
	{
		bool L_1 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_1)
		{
			goto IL_005e;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_2 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_3 = (uint8_t*)(&L_2->___byte_0);
		V_1 = L_3;
		uint8_t* L_4 = V_1;
		uintptr_t L_5 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_4,NULL));
		V_0 = (uint8_t*)L_5;
		V_2 = 0;
		goto IL_0052;
	}

IL_003f:
	{
		uint8_t* L_6 = V_0;
		int32_t L_7 = V_2;
		il2cpp_codegen_memcpy(L_8, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_9;
		il2cpp_codegen_box_unbox(L_8, (&L_9), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		*(((int8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_6, L_7)))) = ((int8_t)L_9);
		int32_t L_10 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_10, 1));
	}

IL_0052:
	{
		int32_t L_11 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_12;
		L_12 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_11) < ((int32_t)L_12)))
		{
			goto IL_003f;
		}
	}
	{
		uintptr_t L_13 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_1 = (uint8_t*)L_13;
		return;
	}

IL_005e:
	{
		bool L_14 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_14)
		{
			goto IL_00b3;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_15 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_16 = (int8_t*)(&L_15->___sbyte_0);
		V_4 = L_16;
		int8_t* L_17 = V_4;
		uintptr_t L_18 = (il2cpp_codegen_conv<uintptr_t,int8_t*,intptr_t,false,false>(L_17,NULL));
		V_3 = (int8_t*)L_18;
		V_5 = 0;
		goto IL_00a5;
	}

IL_008f:
	{
		int8_t* L_19 = V_3;
		int32_t L_20 = V_5;
		il2cpp_codegen_memcpy(L_21, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_22;
		il2cpp_codegen_box_unbox(L_21, (&L_22), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		*(((int8_t*)il2cpp_codegen_add((intptr_t)L_19, L_20))) = L_22;
		int32_t L_23 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_00a5:
	{
		int32_t L_24 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_25;
		L_25 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_24) < ((int32_t)L_25)))
		{
			goto IL_008f;
		}
	}
	{
		uintptr_t L_26 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_4 = (int8_t*)L_26;
		return;
	}

IL_00b3:
	{
		bool L_27 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_27)
		{
			goto IL_010d;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_28 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_29 = (uint16_t*)(&L_28->___uint16_0);
		V_7 = L_29;
		uint16_t* L_30 = V_7;
		uintptr_t L_31 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>(L_30,NULL));
		V_6 = (uint16_t*)L_31;
		V_8 = 0;
		goto IL_00ff;
	}

IL_00e5:
	{
		uint16_t* L_32 = V_6;
		int32_t L_33 = V_8;
		intptr_t L_34 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_33,NULL));
		il2cpp_codegen_memcpy(L_35, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_36;
		il2cpp_codegen_box_unbox(L_35, (&L_36), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		*(((int16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_32, ((intptr_t)il2cpp_codegen_multiply(L_34, 2)))))) = ((int16_t)L_36);
		int32_t L_37 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_37, 1));
	}

IL_00ff:
	{
		int32_t L_38 = V_8;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_39;
		L_39 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_38) < ((int32_t)L_39)))
		{
			goto IL_00e5;
		}
	}
	{
		uintptr_t L_40 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_7 = (uint16_t*)L_40;
		return;
	}

IL_010d:
	{
		bool L_41 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_41)
		{
			goto IL_0167;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_42 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_43 = (int16_t*)(&L_42->___int16_0);
		V_10 = L_43;
		int16_t* L_44 = V_10;
		uintptr_t L_45 = (il2cpp_codegen_conv<uintptr_t,int16_t*,intptr_t,false,false>(L_44,NULL));
		V_9 = (int16_t*)L_45;
		V_11 = 0;
		goto IL_0159;
	}

IL_013f:
	{
		int16_t* L_46 = V_9;
		int32_t L_47 = V_11;
		intptr_t L_48 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_47,NULL));
		il2cpp_codegen_memcpy(L_49, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_50;
		il2cpp_codegen_box_unbox(L_49, (&L_50), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		*(((int16_t*)il2cpp_codegen_add((intptr_t)L_46, ((intptr_t)il2cpp_codegen_multiply(L_48, 2))))) = L_50;
		int32_t L_51 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_0159:
	{
		int32_t L_52 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_53;
		L_53 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_013f;
		}
	}
	{
		uintptr_t L_54 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_10 = (int16_t*)L_54;
		return;
	}

IL_0167:
	{
		bool L_55 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_55)
		{
			goto IL_01c1;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_56 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_57 = (uint32_t*)(&L_56->___uint32_0);
		V_13 = L_57;
		uint32_t* L_58 = V_13;
		uintptr_t L_59 = (il2cpp_codegen_conv<uintptr_t,uint32_t*,intptr_t,false,false>(L_58,NULL));
		V_12 = (uint32_t*)L_59;
		V_14 = 0;
		goto IL_01b3;
	}

IL_0199:
	{
		uint32_t* L_60 = V_12;
		int32_t L_61 = V_14;
		intptr_t L_62 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_61,NULL));
		il2cpp_codegen_memcpy(L_63, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_64;
		il2cpp_codegen_box_unbox(L_63, (&L_64), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		*(((int32_t*)((uint32_t*)il2cpp_codegen_add((intptr_t)L_60, ((intptr_t)il2cpp_codegen_multiply(L_62, 4)))))) = ((int32_t)L_64);
		int32_t L_65 = V_14;
		V_14 = ((int32_t)il2cpp_codegen_add(L_65, 1));
	}

IL_01b3:
	{
		int32_t L_66 = V_14;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_67;
		L_67 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_66) < ((int32_t)L_67)))
		{
			goto IL_0199;
		}
	}
	{
		uintptr_t L_68 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_13 = (uint32_t*)L_68;
		return;
	}

IL_01c1:
	{
		bool L_69 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_69)
		{
			goto IL_021b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_70 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_71 = (int32_t*)(&L_70->___int32_0);
		V_16 = L_71;
		int32_t* L_72 = V_16;
		uintptr_t L_73 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>(L_72,NULL));
		V_15 = (int32_t*)L_73;
		V_17 = 0;
		goto IL_020d;
	}

IL_01f3:
	{
		int32_t* L_74 = V_15;
		int32_t L_75 = V_17;
		intptr_t L_76 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_75,NULL));
		il2cpp_codegen_memcpy(L_77, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_78;
		il2cpp_codegen_box_unbox(L_77, (&L_78), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_74, ((intptr_t)il2cpp_codegen_multiply(L_76, 4))))) = L_78;
		int32_t L_79 = V_17;
		V_17 = ((int32_t)il2cpp_codegen_add(L_79, 1));
	}

IL_020d:
	{
		int32_t L_80 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_81;
		L_81 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_80) < ((int32_t)L_81)))
		{
			goto IL_01f3;
		}
	}
	{
		uintptr_t L_82 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_16 = (int32_t*)L_82;
		return;
	}

IL_021b:
	{
		bool L_83 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_83)
		{
			goto IL_0275;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_84 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_85 = (uint64_t*)(&L_84->___uint64_0);
		V_19 = L_85;
		uint64_t* L_86 = V_19;
		uintptr_t L_87 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_86,NULL));
		V_18 = (uint64_t*)L_87;
		V_20 = 0;
		goto IL_0267;
	}

IL_024d:
	{
		uint64_t* L_88 = V_18;
		int32_t L_89 = V_20;
		intptr_t L_90 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_89,NULL));
		il2cpp_codegen_memcpy(L_91, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_92;
		il2cpp_codegen_box_unbox(L_91, (&L_92), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		*(((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_88, ((intptr_t)il2cpp_codegen_multiply(L_90, 8)))))) = ((int64_t)L_92);
		int32_t L_93 = V_20;
		V_20 = ((int32_t)il2cpp_codegen_add(L_93, 1));
	}

IL_0267:
	{
		int32_t L_94 = V_20;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_95;
		L_95 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_94) < ((int32_t)L_95)))
		{
			goto IL_024d;
		}
	}
	{
		uintptr_t L_96 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_19 = (uint64_t*)L_96;
		return;
	}

IL_0275:
	{
		bool L_97 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_97)
		{
			goto IL_02cf;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_98 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_99 = (int64_t*)(&L_98->___int64_0);
		V_22 = L_99;
		int64_t* L_100 = V_22;
		uintptr_t L_101 = (il2cpp_codegen_conv<uintptr_t,int64_t*,intptr_t,false,false>(L_100,NULL));
		V_21 = (int64_t*)L_101;
		V_23 = 0;
		goto IL_02c1;
	}

IL_02a7:
	{
		int64_t* L_102 = V_21;
		int32_t L_103 = V_23;
		intptr_t L_104 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_103,NULL));
		il2cpp_codegen_memcpy(L_105, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_106;
		il2cpp_codegen_box_unbox(L_105, (&L_106), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		*(((int64_t*)il2cpp_codegen_add((intptr_t)L_102, ((intptr_t)il2cpp_codegen_multiply(L_104, 8))))) = L_106;
		int32_t L_107 = V_23;
		V_23 = ((int32_t)il2cpp_codegen_add(L_107, 1));
	}

IL_02c1:
	{
		int32_t L_108 = V_23;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_109;
		L_109 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_108) < ((int32_t)L_109)))
		{
			goto IL_02a7;
		}
	}
	{
		uintptr_t L_110 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_22 = (int64_t*)L_110;
		return;
	}

IL_02cf:
	{
		bool L_111 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_111)
		{
			goto IL_0329;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_112 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_113 = (float*)(&L_112->___single_0);
		V_25 = L_113;
		float* L_114 = V_25;
		uintptr_t L_115 = (il2cpp_codegen_conv<uintptr_t,float*,intptr_t,false,false>(L_114,NULL));
		V_24 = (float*)L_115;
		V_26 = 0;
		goto IL_031b;
	}

IL_0301:
	{
		float* L_116 = V_24;
		int32_t L_117 = V_26;
		intptr_t L_118 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_117,NULL));
		il2cpp_codegen_memcpy(L_119, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_120;
		il2cpp_codegen_box_unbox(L_119, (&L_120), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		*(((float*)il2cpp_codegen_add((intptr_t)L_116, ((intptr_t)il2cpp_codegen_multiply(L_118, 4))))) = L_120;
		int32_t L_121 = V_26;
		V_26 = ((int32_t)il2cpp_codegen_add(L_121, 1));
	}

IL_031b:
	{
		int32_t L_122 = V_26;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_123;
		L_123 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_122) < ((int32_t)L_123)))
		{
			goto IL_0301;
		}
	}
	{
		uintptr_t L_124 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_25 = (float*)L_124;
		return;
	}

IL_0329:
	{
		bool L_125 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_125)
		{
			goto IL_0a55;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_126 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_127 = (double*)(&L_126->___double_0);
		V_28 = L_127;
		double* L_128 = V_28;
		uintptr_t L_129 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>(L_128,NULL));
		V_27 = (double*)L_129;
		V_29 = 0;
		goto IL_0378;
	}

IL_035e:
	{
		double* L_130 = V_27;
		int32_t L_131 = V_29;
		intptr_t L_132 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_131,NULL));
		il2cpp_codegen_memcpy(L_133, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_134;
		il2cpp_codegen_box_unbox(L_133, (&L_134), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		*(((double*)il2cpp_codegen_add((intptr_t)L_130, ((intptr_t)il2cpp_codegen_multiply(L_132, 8))))) = L_134;
		int32_t L_135 = V_29;
		V_29 = ((int32_t)il2cpp_codegen_add(L_135, 1));
	}

IL_0378:
	{
		int32_t L_136 = V_29;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_137;
		L_137 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_136) < ((int32_t)L_137)))
		{
			goto IL_035e;
		}
	}
	{
		uintptr_t L_138 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_28 = (double*)L_138;
		return;
	}

IL_0386:
	{
		bool L_139 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_139)
		{
			goto IL_0505;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_140 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_141, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_142;
		il2cpp_codegen_box_unbox(L_141, (&L_142), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_140->___byte_0 = L_142;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_143 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_144, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_145;
		il2cpp_codegen_box_unbox(L_144, (&L_145), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_143->___byte_1 = L_145;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_146 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_147, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_148;
		il2cpp_codegen_box_unbox(L_147, (&L_148), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_146->___byte_2 = L_148;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_149 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_150, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_151;
		il2cpp_codegen_box_unbox(L_150, (&L_151), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_149->___byte_3 = L_151;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_152 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_153, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_154;
		il2cpp_codegen_box_unbox(L_153, (&L_154), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_152->___byte_4 = L_154;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_155 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_156, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_157;
		il2cpp_codegen_box_unbox(L_156, (&L_157), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_155->___byte_5 = L_157;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_158 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_159, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_160;
		il2cpp_codegen_box_unbox(L_159, (&L_160), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_158->___byte_6 = L_160;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_161 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_162, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_163;
		il2cpp_codegen_box_unbox(L_162, (&L_163), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_161->___byte_7 = L_163;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_164 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_165, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_166;
		il2cpp_codegen_box_unbox(L_165, (&L_166), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_164->___byte_8 = L_166;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_167 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_168, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_169;
		il2cpp_codegen_box_unbox(L_168, (&L_169), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_167->___byte_9 = L_169;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_170 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_171, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_172;
		il2cpp_codegen_box_unbox(L_171, (&L_172), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_170->___byte_10 = L_172;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_173 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_174, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_175;
		il2cpp_codegen_box_unbox(L_174, (&L_175), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_173->___byte_11 = L_175;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_176 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_177, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_178;
		il2cpp_codegen_box_unbox(L_177, (&L_178), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_176->___byte_12 = L_178;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_179 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_180, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_181;
		il2cpp_codegen_box_unbox(L_180, (&L_181), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_179->___byte_13 = L_181;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_182 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_183, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_184;
		il2cpp_codegen_box_unbox(L_183, (&L_184), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_182->___byte_14 = L_184;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_185 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_186, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_187;
		il2cpp_codegen_box_unbox(L_186, (&L_187), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		L_185->___byte_15 = L_187;
		return;
	}

IL_0505:
	{
		bool L_188 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_188)
		{
			goto IL_0684;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_189 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_190, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_191;
		il2cpp_codegen_box_unbox(L_190, (&L_191), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_189->___sbyte_0 = L_191;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_192 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_193, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_194;
		il2cpp_codegen_box_unbox(L_193, (&L_194), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_192->___sbyte_1 = L_194;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_195 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_196, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_197;
		il2cpp_codegen_box_unbox(L_196, (&L_197), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_195->___sbyte_2 = L_197;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_198 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_199, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_200;
		il2cpp_codegen_box_unbox(L_199, (&L_200), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_198->___sbyte_3 = L_200;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_201 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_202, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_203;
		il2cpp_codegen_box_unbox(L_202, (&L_203), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_201->___sbyte_4 = L_203;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_204 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_205, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_206;
		il2cpp_codegen_box_unbox(L_205, (&L_206), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_204->___sbyte_5 = L_206;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_207 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_208, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_209;
		il2cpp_codegen_box_unbox(L_208, (&L_209), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_207->___sbyte_6 = L_209;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_210 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_211, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_212;
		il2cpp_codegen_box_unbox(L_211, (&L_212), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_210->___sbyte_7 = L_212;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_213 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_214, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_215;
		il2cpp_codegen_box_unbox(L_214, (&L_215), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_213->___sbyte_8 = L_215;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_216 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_217, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_218;
		il2cpp_codegen_box_unbox(L_217, (&L_218), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_216->___sbyte_9 = L_218;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_219 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_220, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_221;
		il2cpp_codegen_box_unbox(L_220, (&L_221), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_219->___sbyte_10 = L_221;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_222 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_223, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_224;
		il2cpp_codegen_box_unbox(L_223, (&L_224), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_222->___sbyte_11 = L_224;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_225 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_226, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_227;
		il2cpp_codegen_box_unbox(L_226, (&L_227), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_225->___sbyte_12 = L_227;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_228 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_229, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_230;
		il2cpp_codegen_box_unbox(L_229, (&L_230), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_228->___sbyte_13 = L_230;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_231 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_232, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_233;
		il2cpp_codegen_box_unbox(L_232, (&L_233), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_231->___sbyte_14 = L_233;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_234 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_235, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_236;
		il2cpp_codegen_box_unbox(L_235, (&L_236), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		L_234->___sbyte_15 = L_236;
		return;
	}

IL_0684:
	{
		bool L_237 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_237)
		{
			goto IL_0753;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_238 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_239, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_240;
		il2cpp_codegen_box_unbox(L_239, (&L_240), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_238->___uint16_0 = L_240;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_241 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_242, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_243;
		il2cpp_codegen_box_unbox(L_242, (&L_243), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_241->___uint16_1 = L_243;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_244 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_245, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_246;
		il2cpp_codegen_box_unbox(L_245, (&L_246), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_244->___uint16_2 = L_246;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_247 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_248, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_249;
		il2cpp_codegen_box_unbox(L_248, (&L_249), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_247->___uint16_3 = L_249;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_250 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_251, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_252;
		il2cpp_codegen_box_unbox(L_251, (&L_252), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_250->___uint16_4 = L_252;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_253 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_254, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_255;
		il2cpp_codegen_box_unbox(L_254, (&L_255), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_253->___uint16_5 = L_255;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_256 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_257, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_258;
		il2cpp_codegen_box_unbox(L_257, (&L_258), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_256->___uint16_6 = L_258;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_259 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_260, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_261;
		il2cpp_codegen_box_unbox(L_260, (&L_261), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		L_259->___uint16_7 = L_261;
		return;
	}

IL_0753:
	{
		bool L_262 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_262)
		{
			goto IL_0822;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_263 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_264, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_265;
		il2cpp_codegen_box_unbox(L_264, (&L_265), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_263->___int16_0 = L_265;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_266 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_267, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_268;
		il2cpp_codegen_box_unbox(L_267, (&L_268), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_266->___int16_1 = L_268;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_269 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_270, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_271;
		il2cpp_codegen_box_unbox(L_270, (&L_271), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_269->___int16_2 = L_271;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_272 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_273, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_274;
		il2cpp_codegen_box_unbox(L_273, (&L_274), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_272->___int16_3 = L_274;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_275 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_276, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_277;
		il2cpp_codegen_box_unbox(L_276, (&L_277), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_275->___int16_4 = L_277;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_278 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_279, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_280;
		il2cpp_codegen_box_unbox(L_279, (&L_280), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_278->___int16_5 = L_280;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_281 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_282, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_283;
		il2cpp_codegen_box_unbox(L_282, (&L_283), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_281->___int16_6 = L_283;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_284 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_285, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_286;
		il2cpp_codegen_box_unbox(L_285, (&L_286), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		L_284->___int16_7 = L_286;
		return;
	}

IL_0822:
	{
		bool L_287 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_287)
		{
			goto IL_0896;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_288 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_289, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_290;
		il2cpp_codegen_box_unbox(L_289, (&L_290), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		L_288->___uint32_0 = L_290;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_291 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_292, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_293;
		il2cpp_codegen_box_unbox(L_292, (&L_293), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		L_291->___uint32_1 = L_293;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_294 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_295, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_296;
		il2cpp_codegen_box_unbox(L_295, (&L_296), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		L_294->___uint32_2 = L_296;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_297 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_298, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_299;
		il2cpp_codegen_box_unbox(L_298, (&L_299), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		L_297->___uint32_3 = L_299;
		return;
	}

IL_0896:
	{
		bool L_300 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_300)
		{
			goto IL_090a;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_301 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_302, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_303;
		il2cpp_codegen_box_unbox(L_302, (&L_303), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		L_301->___int32_0 = L_303;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_304 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_305, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_306;
		il2cpp_codegen_box_unbox(L_305, (&L_306), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		L_304->___int32_1 = L_306;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_307 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_308, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_309;
		il2cpp_codegen_box_unbox(L_308, (&L_309), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		L_307->___int32_2 = L_309;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_310 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_311, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_312;
		il2cpp_codegen_box_unbox(L_311, (&L_312), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		L_310->___int32_3 = L_312;
		return;
	}

IL_090a:
	{
		bool L_313 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_313)
		{
			goto IL_0952;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_314 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_315, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_316;
		il2cpp_codegen_box_unbox(L_315, (&L_316), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		L_314->___uint64_0 = L_316;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_317 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_318, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_319;
		il2cpp_codegen_box_unbox(L_318, (&L_319), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		L_317->___uint64_1 = L_319;
		return;
	}

IL_0952:
	{
		bool L_320 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_320)
		{
			goto IL_099a;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_321 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_322, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_323;
		il2cpp_codegen_box_unbox(L_322, (&L_323), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		L_321->___int64_0 = L_323;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_324 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_325, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_326;
		il2cpp_codegen_box_unbox(L_325, (&L_326), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		L_324->___int64_1 = L_326;
		return;
	}

IL_099a:
	{
		bool L_327 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_327)
		{
			goto IL_0a0e;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_328 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_329, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_330;
		il2cpp_codegen_box_unbox(L_329, (&L_330), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		L_328->___single_0 = L_330;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_331 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_332, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_333;
		il2cpp_codegen_box_unbox(L_332, (&L_333), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		L_331->___single_1 = L_333;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_334 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_335, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_336;
		il2cpp_codegen_box_unbox(L_335, (&L_336), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		L_334->___single_2 = L_336;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_337 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_338, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_339;
		il2cpp_codegen_box_unbox(L_338, (&L_339), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		L_337->___single_3 = L_339;
		return;
	}

IL_0a0e:
	{
		bool L_340 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_340)
		{
			goto IL_0a55;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_341 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_342, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_343;
		il2cpp_codegen_box_unbox(L_342, (&L_343), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		L_341->___double_0 = L_343;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_344 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		il2cpp_codegen_memcpy(L_345, ___0_value, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_346;
		il2cpp_codegen_box_unbox(L_345, (&L_346), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		L_344->___double_1 = L_346;
	}

IL_0a55:
	{
		return;
	}
}
// Method Definition Index: 8059
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, void* ___0_dataPointer, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		void* L_0 = ___0_dataPointer;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		((  void (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, void*, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4)))(__this, L_0, 0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 4));
		return;
	}
}
// Method Definition Index: 8060
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mAD567DC632B01A95C6F418F1C6265F295D1EB0A9_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, void* ___0_dataPointer, int32_t ___1_offset, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	uint8_t* V_1 = NULL;
	uint8_t* V_2 = NULL;
	int32_t V_3 = 0;
	int8_t* V_4 = NULL;
	int8_t* V_5 = NULL;
	int8_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint16_t* V_8 = NULL;
	uint16_t* V_9 = NULL;
	uint16_t* V_10 = NULL;
	int32_t V_11 = 0;
	int16_t* V_12 = NULL;
	int16_t* V_13 = NULL;
	int16_t* V_14 = NULL;
	int32_t V_15 = 0;
	uint32_t* V_16 = NULL;
	uint32_t* V_17 = NULL;
	uint32_t* V_18 = NULL;
	int32_t V_19 = 0;
	int32_t* V_20 = NULL;
	int32_t* V_21 = NULL;
	int32_t* V_22 = NULL;
	int32_t V_23 = 0;
	uint64_t* V_24 = NULL;
	uint64_t* V_25 = NULL;
	uint64_t* V_26 = NULL;
	int32_t V_27 = 0;
	int64_t* V_28 = NULL;
	int64_t* V_29 = NULL;
	int64_t* V_30 = NULL;
	int32_t V_31 = 0;
	float* V_32 = NULL;
	float* V_33 = NULL;
	float* V_34 = NULL;
	int32_t V_35 = 0;
	double* V_36 = NULL;
	double* V_37 = NULL;
	double* V_38 = NULL;
	int32_t V_39 = 0;
	{
		il2cpp_codegen_initobj(__this, sizeof(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2));
		bool L_0 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_0)
		{
			goto IL_0053;
		}
	}
	{
		void* L_1 = ___0_dataPointer;
		V_0 = (uint8_t*)L_1;
		uint8_t* L_2 = V_0;
		int32_t L_3 = ___1_offset;
		V_0 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_2, L_3));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_4 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_5 = (uint8_t*)(&L_4->___byte_0);
		V_2 = L_5;
		uint8_t* L_6 = V_2;
		uintptr_t L_7 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_6,NULL));
		V_1 = (uint8_t*)L_7;
		V_3 = 0;
		goto IL_0047;
	}

IL_003b:
	{
		uint8_t* L_8 = V_1;
		int32_t L_9 = V_3;
		uint8_t* L_10 = V_0;
		int32_t L_11 = V_3;
		int32_t L_12 = ((int32_t)*(((uint8_t*)il2cpp_codegen_add((intptr_t)L_10, L_11))));
		*(((int8_t*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_8, L_9)))) = ((int8_t)L_12);
		int32_t L_13 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0047:
	{
		int32_t L_14 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_15;
		L_15 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_14) < ((int32_t)L_15)))
		{
			goto IL_003b;
		}
	}
	{
		uintptr_t L_16 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_2 = (uint8_t*)L_16;
		return;
	}

IL_0053:
	{
		bool L_17 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_17)
		{
			goto IL_00ae;
		}
	}
	{
		void* L_18 = ___0_dataPointer;
		V_4 = (int8_t*)L_18;
		int8_t* L_19 = V_4;
		int32_t L_20 = ___1_offset;
		V_4 = ((int8_t*)il2cpp_codegen_add((intptr_t)L_19, L_20));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_21 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_22 = (int8_t*)(&L_21->___sbyte_0);
		V_6 = L_22;
		int8_t* L_23 = V_6;
		uintptr_t L_24 = (il2cpp_codegen_conv<uintptr_t,int8_t*,intptr_t,false,false>(L_23,NULL));
		V_5 = (int8_t*)L_24;
		V_7 = 0;
		goto IL_00a0;
	}

IL_008e:
	{
		int8_t* L_25 = V_5;
		int32_t L_26 = V_7;
		int8_t* L_27 = V_4;
		int32_t L_28 = V_7;
		int32_t L_29 = ((int32_t)*(((int8_t*)il2cpp_codegen_add((intptr_t)L_27, L_28))));
		*(((int8_t*)il2cpp_codegen_add((intptr_t)L_25, L_26))) = ((int8_t)L_29);
		int32_t L_30 = V_7;
		V_7 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_00a0:
	{
		int32_t L_31 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_32;
		L_32 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_31) < ((int32_t)L_32)))
		{
			goto IL_008e;
		}
	}
	{
		uintptr_t L_33 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_6 = (int8_t*)L_33;
		return;
	}

IL_00ae:
	{
		bool L_34 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_34)
		{
			goto IL_0112;
		}
	}
	{
		void* L_35 = ___0_dataPointer;
		V_8 = (uint16_t*)L_35;
		uint16_t* L_36 = V_8;
		int32_t L_37 = ___1_offset;
		intptr_t L_38 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_37,NULL));
		V_8 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_36, ((intptr_t)il2cpp_codegen_multiply(L_38, 2))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_39 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_40 = (uint16_t*)(&L_39->___uint16_0);
		V_10 = L_40;
		uint16_t* L_41 = V_10;
		uintptr_t L_42 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>(L_41,NULL));
		V_9 = (uint16_t*)L_42;
		V_11 = 0;
		goto IL_0104;
	}

IL_00ec:
	{
		uint16_t* L_43 = V_9;
		int32_t L_44 = V_11;
		intptr_t L_45 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_44,NULL));
		uint16_t* L_46 = V_8;
		int32_t L_47 = V_11;
		intptr_t L_48 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_47,NULL));
		int32_t L_49 = ((int32_t)*(((uint16_t*)il2cpp_codegen_add((intptr_t)L_46, ((intptr_t)il2cpp_codegen_multiply(L_48, 2))))));
		*(((int16_t*)((uint16_t*)il2cpp_codegen_add((intptr_t)L_43, ((intptr_t)il2cpp_codegen_multiply(L_45, 2)))))) = ((int16_t)L_49);
		int32_t L_50 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_50, 1));
	}

IL_0104:
	{
		int32_t L_51 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_52;
		L_52 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_51) < ((int32_t)L_52)))
		{
			goto IL_00ec;
		}
	}
	{
		uintptr_t L_53 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_10 = (uint16_t*)L_53;
		return;
	}

IL_0112:
	{
		bool L_54 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_54)
		{
			goto IL_0176;
		}
	}
	{
		void* L_55 = ___0_dataPointer;
		V_12 = (int16_t*)L_55;
		int16_t* L_56 = V_12;
		int32_t L_57 = ___1_offset;
		intptr_t L_58 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_57,NULL));
		V_12 = ((int16_t*)il2cpp_codegen_add((intptr_t)L_56, ((intptr_t)il2cpp_codegen_multiply(L_58, 2))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_59 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_60 = (int16_t*)(&L_59->___int16_0);
		V_14 = L_60;
		int16_t* L_61 = V_14;
		uintptr_t L_62 = (il2cpp_codegen_conv<uintptr_t,int16_t*,intptr_t,false,false>(L_61,NULL));
		V_13 = (int16_t*)L_62;
		V_15 = 0;
		goto IL_0168;
	}

IL_0150:
	{
		int16_t* L_63 = V_13;
		int32_t L_64 = V_15;
		intptr_t L_65 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_64,NULL));
		int16_t* L_66 = V_12;
		int32_t L_67 = V_15;
		intptr_t L_68 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_67,NULL));
		int32_t L_69 = ((int32_t)*(((int16_t*)il2cpp_codegen_add((intptr_t)L_66, ((intptr_t)il2cpp_codegen_multiply(L_68, 2))))));
		*(((int16_t*)il2cpp_codegen_add((intptr_t)L_63, ((intptr_t)il2cpp_codegen_multiply(L_65, 2))))) = ((int16_t)L_69);
		int32_t L_70 = V_15;
		V_15 = ((int32_t)il2cpp_codegen_add(L_70, 1));
	}

IL_0168:
	{
		int32_t L_71 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_72;
		L_72 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_71) < ((int32_t)L_72)))
		{
			goto IL_0150;
		}
	}
	{
		uintptr_t L_73 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_14 = (int16_t*)L_73;
		return;
	}

IL_0176:
	{
		bool L_74 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_74)
		{
			goto IL_01da;
		}
	}
	{
		void* L_75 = ___0_dataPointer;
		V_16 = (uint32_t*)L_75;
		uint32_t* L_76 = V_16;
		int32_t L_77 = ___1_offset;
		intptr_t L_78 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_77,NULL));
		V_16 = ((uint32_t*)il2cpp_codegen_add((intptr_t)L_76, ((intptr_t)il2cpp_codegen_multiply(L_78, 4))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_79 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_80 = (uint32_t*)(&L_79->___uint32_0);
		V_18 = L_80;
		uint32_t* L_81 = V_18;
		uintptr_t L_82 = (il2cpp_codegen_conv<uintptr_t,uint32_t*,intptr_t,false,false>(L_81,NULL));
		V_17 = (uint32_t*)L_82;
		V_19 = 0;
		goto IL_01cc;
	}

IL_01b4:
	{
		uint32_t* L_83 = V_17;
		int32_t L_84 = V_19;
		intptr_t L_85 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_84,NULL));
		uint32_t* L_86 = V_16;
		int32_t L_87 = V_19;
		intptr_t L_88 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_87,NULL));
		int32_t L_89 = ((int32_t)*(((uint32_t*)il2cpp_codegen_add((intptr_t)L_86, ((intptr_t)il2cpp_codegen_multiply(L_88, 4))))));
		*(((int32_t*)((uint32_t*)il2cpp_codegen_add((intptr_t)L_83, ((intptr_t)il2cpp_codegen_multiply(L_85, 4)))))) = L_89;
		int32_t L_90 = V_19;
		V_19 = ((int32_t)il2cpp_codegen_add(L_90, 1));
	}

IL_01cc:
	{
		int32_t L_91 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_92;
		L_92 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_91) < ((int32_t)L_92)))
		{
			goto IL_01b4;
		}
	}
	{
		uintptr_t L_93 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_18 = (uint32_t*)L_93;
		return;
	}

IL_01da:
	{
		bool L_94 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_94)
		{
			goto IL_023e;
		}
	}
	{
		void* L_95 = ___0_dataPointer;
		V_20 = (int32_t*)L_95;
		int32_t* L_96 = V_20;
		int32_t L_97 = ___1_offset;
		intptr_t L_98 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_97,NULL));
		V_20 = ((int32_t*)il2cpp_codegen_add((intptr_t)L_96, ((intptr_t)il2cpp_codegen_multiply(L_98, 4))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_99 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_100 = (int32_t*)(&L_99->___int32_0);
		V_22 = L_100;
		int32_t* L_101 = V_22;
		uintptr_t L_102 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>(L_101,NULL));
		V_21 = (int32_t*)L_102;
		V_23 = 0;
		goto IL_0230;
	}

IL_0218:
	{
		int32_t* L_103 = V_21;
		int32_t L_104 = V_23;
		intptr_t L_105 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_104,NULL));
		int32_t* L_106 = V_20;
		int32_t L_107 = V_23;
		intptr_t L_108 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_107,NULL));
		int32_t L_109 = *(((int32_t*)il2cpp_codegen_add((intptr_t)L_106, ((intptr_t)il2cpp_codegen_multiply(L_108, 4)))));
		*(((int32_t*)il2cpp_codegen_add((intptr_t)L_103, ((intptr_t)il2cpp_codegen_multiply(L_105, 4))))) = L_109;
		int32_t L_110 = V_23;
		V_23 = ((int32_t)il2cpp_codegen_add(L_110, 1));
	}

IL_0230:
	{
		int32_t L_111 = V_23;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_112;
		L_112 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_111) < ((int32_t)L_112)))
		{
			goto IL_0218;
		}
	}
	{
		uintptr_t L_113 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_22 = (int32_t*)L_113;
		return;
	}

IL_023e:
	{
		bool L_114 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_114)
		{
			goto IL_02a2;
		}
	}
	{
		void* L_115 = ___0_dataPointer;
		V_24 = (uint64_t*)L_115;
		uint64_t* L_116 = V_24;
		int32_t L_117 = ___1_offset;
		intptr_t L_118 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_117,NULL));
		V_24 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_116, ((intptr_t)il2cpp_codegen_multiply(L_118, 8))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_119 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_120 = (uint64_t*)(&L_119->___uint64_0);
		V_26 = L_120;
		uint64_t* L_121 = V_26;
		uintptr_t L_122 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_121,NULL));
		V_25 = (uint64_t*)L_122;
		V_27 = 0;
		goto IL_0294;
	}

IL_027c:
	{
		uint64_t* L_123 = V_25;
		int32_t L_124 = V_27;
		intptr_t L_125 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_124,NULL));
		uint64_t* L_126 = V_24;
		int32_t L_127 = V_27;
		intptr_t L_128 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_127,NULL));
		int64_t L_129 = *(((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_126, ((intptr_t)il2cpp_codegen_multiply(L_128, 8))))));
		*(((int64_t*)((uint64_t*)il2cpp_codegen_add((intptr_t)L_123, ((intptr_t)il2cpp_codegen_multiply(L_125, 8)))))) = L_129;
		int32_t L_130 = V_27;
		V_27 = ((int32_t)il2cpp_codegen_add(L_130, 1));
	}

IL_0294:
	{
		int32_t L_131 = V_27;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_132;
		L_132 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_131) < ((int32_t)L_132)))
		{
			goto IL_027c;
		}
	}
	{
		uintptr_t L_133 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_26 = (uint64_t*)L_133;
		return;
	}

IL_02a2:
	{
		bool L_134 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_134)
		{
			goto IL_0306;
		}
	}
	{
		void* L_135 = ___0_dataPointer;
		V_28 = (int64_t*)L_135;
		int64_t* L_136 = V_28;
		int32_t L_137 = ___1_offset;
		intptr_t L_138 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_137,NULL));
		V_28 = ((int64_t*)il2cpp_codegen_add((intptr_t)L_136, ((intptr_t)il2cpp_codegen_multiply(L_138, 8))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_139 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_140 = (int64_t*)(&L_139->___int64_0);
		V_30 = L_140;
		int64_t* L_141 = V_30;
		uintptr_t L_142 = (il2cpp_codegen_conv<uintptr_t,int64_t*,intptr_t,false,false>(L_141,NULL));
		V_29 = (int64_t*)L_142;
		V_31 = 0;
		goto IL_02f8;
	}

IL_02e0:
	{
		int64_t* L_143 = V_29;
		int32_t L_144 = V_31;
		intptr_t L_145 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_144,NULL));
		int64_t* L_146 = V_28;
		int32_t L_147 = V_31;
		intptr_t L_148 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_147,NULL));
		int64_t L_149 = *(((int64_t*)il2cpp_codegen_add((intptr_t)L_146, ((intptr_t)il2cpp_codegen_multiply(L_148, 8)))));
		*(((int64_t*)il2cpp_codegen_add((intptr_t)L_143, ((intptr_t)il2cpp_codegen_multiply(L_145, 8))))) = L_149;
		int32_t L_150 = V_31;
		V_31 = ((int32_t)il2cpp_codegen_add(L_150, 1));
	}

IL_02f8:
	{
		int32_t L_151 = V_31;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_152;
		L_152 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_151) < ((int32_t)L_152)))
		{
			goto IL_02e0;
		}
	}
	{
		uintptr_t L_153 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_30 = (int64_t*)L_153;
		return;
	}

IL_0306:
	{
		bool L_154 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_154)
		{
			goto IL_036a;
		}
	}
	{
		void* L_155 = ___0_dataPointer;
		V_32 = (float*)L_155;
		float* L_156 = V_32;
		int32_t L_157 = ___1_offset;
		intptr_t L_158 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_157,NULL));
		V_32 = ((float*)il2cpp_codegen_add((intptr_t)L_156, ((intptr_t)il2cpp_codegen_multiply(L_158, 4))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_159 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_160 = (float*)(&L_159->___single_0);
		V_34 = L_160;
		float* L_161 = V_34;
		uintptr_t L_162 = (il2cpp_codegen_conv<uintptr_t,float*,intptr_t,false,false>(L_161,NULL));
		V_33 = (float*)L_162;
		V_35 = 0;
		goto IL_035c;
	}

IL_0344:
	{
		float* L_163 = V_33;
		int32_t L_164 = V_35;
		intptr_t L_165 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_164,NULL));
		float* L_166 = V_32;
		int32_t L_167 = V_35;
		intptr_t L_168 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_167,NULL));
		float L_169 = *(((float*)il2cpp_codegen_add((intptr_t)L_166, ((intptr_t)il2cpp_codegen_multiply(L_168, 4)))));
		*(((float*)il2cpp_codegen_add((intptr_t)L_163, ((intptr_t)il2cpp_codegen_multiply(L_165, 4))))) = L_169;
		int32_t L_170 = V_35;
		V_35 = ((int32_t)il2cpp_codegen_add(L_170, 1));
	}

IL_035c:
	{
		int32_t L_171 = V_35;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_172;
		L_172 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_171) < ((int32_t)L_172)))
		{
			goto IL_0344;
		}
	}
	{
		uintptr_t L_173 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_34 = (float*)L_173;
		return;
	}

IL_036a:
	{
		bool L_174 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_174)
		{
			goto IL_03ce;
		}
	}
	{
		void* L_175 = ___0_dataPointer;
		V_36 = (double*)L_175;
		double* L_176 = V_36;
		int32_t L_177 = ___1_offset;
		intptr_t L_178 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_177,NULL));
		V_36 = ((double*)il2cpp_codegen_add((intptr_t)L_176, ((intptr_t)il2cpp_codegen_multiply(L_178, 8))));
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_179 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_180 = (double*)(&L_179->___double_0);
		V_38 = L_180;
		double* L_181 = V_38;
		uintptr_t L_182 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>(L_181,NULL));
		V_37 = (double*)L_182;
		V_39 = 0;
		goto IL_03c0;
	}

IL_03a8:
	{
		double* L_183 = V_37;
		int32_t L_184 = V_39;
		intptr_t L_185 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_184,NULL));
		double* L_186 = V_36;
		int32_t L_187 = V_39;
		intptr_t L_188 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_187,NULL));
		double L_189 = *(((double*)il2cpp_codegen_add((intptr_t)L_186, ((intptr_t)il2cpp_codegen_multiply(L_188, 8)))));
		*(((double*)il2cpp_codegen_add((intptr_t)L_183, ((intptr_t)il2cpp_codegen_multiply(L_185, 8))))) = L_189;
		int32_t L_190 = V_39;
		V_39 = ((int32_t)il2cpp_codegen_add(L_190, 1));
	}

IL_03c0:
	{
		int32_t L_191 = V_39;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_192;
		L_192 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_191) < ((int32_t)L_192)))
		{
			goto IL_03a8;
		}
	}
	{
		uintptr_t L_193 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		V_38 = (double*)L_193;
		return;
	}

IL_03ce:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_194 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_194, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_194, method);
	}
}
// Method Definition Index: 8061
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* ___0_existingRegister, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_0 = ___0_existingRegister;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_1 = (*(Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)L_0);
		__this->___register = L_1;
		return;
	}
}
// Method Definition Index: 8062
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1_get_Item_m301D7183D2063DC97710DCD2CEF970E7A67EB21C_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, int32_t ___0_index, Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_16 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_25 = L_16;
	const Il2CppFullySharedGenericStruct L_35 = L_16;
	const Il2CppFullySharedGenericStruct L_45 = L_16;
	const Il2CppFullySharedGenericStruct L_55 = L_16;
	const Il2CppFullySharedGenericStruct L_65 = L_16;
	const Il2CppFullySharedGenericStruct L_75 = L_16;
	const Il2CppFullySharedGenericStruct L_85 = L_16;
	const Il2CppFullySharedGenericStruct L_95 = L_16;
	const Il2CppFullySharedGenericStruct L_105 = L_16;
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int8_t* V_1 = NULL;
	uint16_t* V_2 = NULL;
	int16_t* V_3 = NULL;
	uint32_t* V_4 = NULL;
	int32_t* V_5 = NULL;
	uint64_t* V_6 = NULL;
	int64_t* V_7 = NULL;
	float* V_8 = NULL;
	double* V_9 = NULL;
	{
		int32_t L_0 = ___0_index;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_1;
		L_1 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_0) >= ((int32_t)L_1)))
		{
			goto IL_000c;
		}
	}
	{
		int32_t L_2 = ___0_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0022;
		}
	}

IL_000c:
	{
		int32_t L_3 = ___0_index;
		int32_t L_4 = L_3;
		RuntimeObject* L_5 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_4);
		String_t* L_6;
		L_6 = SR_Format_m9E8DC9AEFDC34AC67473EFAEAB78C5066C1A0D09(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral491788442E76F5D7830F0DBFCF8EDD98854F636F)), L_5, NULL);
		IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82* L_7 = (IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IndexOutOfRangeException_t7ECB35264FB6CA8FAA516BD958F4B2ADC78E8A82_il2cpp_TypeInfo_var)));
		IndexOutOfRangeException__ctor_mFD06819F05B815BE2D6E826D4E04F4C449D0A425(L_7, L_6, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_7, method);
	}

IL_0022:
	{
		bool L_8 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_8)
		{
			goto IL_0059;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_9 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_10 = (uint8_t*)(&L_9->___byte_0);
		V_0 = L_10;
		uint8_t* L_11 = V_0;
		uintptr_t L_12 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>(L_11,NULL));
		int32_t L_13 = ___0_index;
		int32_t L_14 = ((int32_t)*(((uint8_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_12, L_13)))));
		uint8_t L_15 = L_14;
		il2cpp_codegen_box_unbox((&L_15), L_16, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_16, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0059:
	{
		bool L_17 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_17)
		{
			goto IL_0090;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_18 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_19 = (int8_t*)(&L_18->___sbyte_0);
		V_1 = L_19;
		int8_t* L_20 = V_1;
		uintptr_t L_21 = (il2cpp_codegen_conv<uintptr_t,int8_t*,intptr_t,false,false>(L_20,NULL));
		int32_t L_22 = ___0_index;
		int32_t L_23 = ((int32_t)*(((int8_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_21, L_22)))));
		int8_t L_24 = L_23;
		il2cpp_codegen_box_unbox((&L_24), L_25, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_25, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0090:
	{
		bool L_26 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_26)
		{
			goto IL_00ca;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_27 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_28 = (uint16_t*)(&L_27->___uint16_0);
		V_2 = L_28;
		uint16_t* L_29 = V_2;
		uintptr_t L_30 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>(L_29,NULL));
		int32_t L_31 = ___0_index;
		intptr_t L_32 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_31,NULL));
		int32_t L_33 = ((int32_t)*(((uint16_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_30, ((intptr_t)il2cpp_codegen_multiply(L_32, 2)))))));
		uint16_t L_34 = L_33;
		il2cpp_codegen_box_unbox((&L_34), L_35, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_35, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00ca:
	{
		bool L_36 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_36)
		{
			goto IL_0104;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_37 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_38 = (int16_t*)(&L_37->___int16_0);
		V_3 = L_38;
		int16_t* L_39 = V_3;
		uintptr_t L_40 = (il2cpp_codegen_conv<uintptr_t,int16_t*,intptr_t,false,false>(L_39,NULL));
		int32_t L_41 = ___0_index;
		intptr_t L_42 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_41,NULL));
		int32_t L_43 = ((int32_t)*(((int16_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_40, ((intptr_t)il2cpp_codegen_multiply(L_42, 2)))))));
		int16_t L_44 = L_43;
		il2cpp_codegen_box_unbox((&L_44), L_45, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_45, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0104:
	{
		bool L_46 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_46)
		{
			goto IL_0140;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_47 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_48 = (uint32_t*)(&L_47->___uint32_0);
		V_4 = L_48;
		uint32_t* L_49 = V_4;
		uintptr_t L_50 = (il2cpp_codegen_conv<uintptr_t,uint32_t*,intptr_t,false,false>(L_49,NULL));
		int32_t L_51 = ___0_index;
		intptr_t L_52 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_51,NULL));
		int32_t L_53 = ((int32_t)*(((uint32_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_50, ((intptr_t)il2cpp_codegen_multiply(L_52, 4)))))));
		uint32_t L_54 = L_53;
		il2cpp_codegen_box_unbox((&L_54), L_55, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_55, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0140:
	{
		bool L_56 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_56)
		{
			goto IL_017c;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_57 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_58 = (int32_t*)(&L_57->___int32_0);
		V_5 = L_58;
		int32_t* L_59 = V_5;
		uintptr_t L_60 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>(L_59,NULL));
		int32_t L_61 = ___0_index;
		intptr_t L_62 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_61,NULL));
		int32_t L_63 = *(((int32_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_60, ((intptr_t)il2cpp_codegen_multiply(L_62, 4))))));
		int32_t L_64 = L_63;
		il2cpp_codegen_box_unbox((&L_64), L_65, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_65, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_017c:
	{
		bool L_66 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_66)
		{
			goto IL_01b8;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_67 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_68 = (uint64_t*)(&L_67->___uint64_0);
		V_6 = L_68;
		uint64_t* L_69 = V_6;
		uintptr_t L_70 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>(L_69,NULL));
		int32_t L_71 = ___0_index;
		intptr_t L_72 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_71,NULL));
		int64_t L_73 = *(((int64_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_70, ((intptr_t)il2cpp_codegen_multiply(L_72, 8))))));
		uint64_t L_74 = L_73;
		il2cpp_codegen_box_unbox((&L_74), L_75, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_75, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_01b8:
	{
		bool L_76 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_76)
		{
			goto IL_01f4;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_77 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_78 = (int64_t*)(&L_77->___int64_0);
		V_7 = L_78;
		int64_t* L_79 = V_7;
		uintptr_t L_80 = (il2cpp_codegen_conv<uintptr_t,int64_t*,intptr_t,false,false>(L_79,NULL));
		int32_t L_81 = ___0_index;
		intptr_t L_82 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_81,NULL));
		int64_t L_83 = *(((int64_t*)((intptr_t)il2cpp_codegen_add((intptr_t)L_80, ((intptr_t)il2cpp_codegen_multiply(L_82, 8))))));
		int64_t L_84 = L_83;
		il2cpp_codegen_box_unbox((&L_84), L_85, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_85, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_01f4:
	{
		bool L_86 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_86)
		{
			goto IL_0230;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_87 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_88 = (float*)(&L_87->___single_0);
		V_8 = L_88;
		float* L_89 = V_8;
		uintptr_t L_90 = (il2cpp_codegen_conv<uintptr_t,float*,intptr_t,false,false>(L_89,NULL));
		int32_t L_91 = ___0_index;
		intptr_t L_92 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_91,NULL));
		float L_93 = *(((float*)((intptr_t)il2cpp_codegen_add((intptr_t)L_90, ((intptr_t)il2cpp_codegen_multiply(L_92, 4))))));
		float L_94 = L_93;
		il2cpp_codegen_box_unbox((&L_94), L_95, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_95, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0230:
	{
		bool L_96 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_96)
		{
			goto IL_026c;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_97 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_98 = (double*)(&L_97->___double_0);
		V_9 = L_98;
		double* L_99 = V_9;
		uintptr_t L_100 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>(L_99,NULL));
		int32_t L_101 = ___0_index;
		intptr_t L_102 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_101,NULL));
		double L_103 = *(((double*)((intptr_t)il2cpp_codegen_add((intptr_t)L_100, ((intptr_t)il2cpp_codegen_multiply(L_102, 8))))));
		double L_104 = L_103;
		il2cpp_codegen_box_unbox((&L_104), L_105, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_105, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_026c:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_106 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_106, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_106, method);
	}
}
// Method Definition Index: 8063
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5)))(__this, ((*(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_AdjustorThunk (RuntimeObject* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_inline(_thisAdjusted, ___0_obj, method);
	return _returnValue;
}
// Method Definition Index: 8064
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_other, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_2 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0031;
		}
	}
	{
		V_0 = 0;
		goto IL_0027;
	}

IL_000b:
	{
		int32_t L_1 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_1, (Il2CppFullySharedGenericStruct*)L_2);
		int32_t L_3 = V_0;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_other), L_3, (Il2CppFullySharedGenericStruct*)L_4);
		bool L_5;
		L_5 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_2, L_4);
		if (L_5)
		{
			goto IL_0023;
		}
	}
	{
		return (bool)0;
	}

IL_0023:
	{
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0027:
	{
		int32_t L_7 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_8;
		L_8 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_000b;
		}
	}
	{
		return (bool)1;
	}

IL_0031:
	{
		bool L_9 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_9)
		{
			goto IL_01f0;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_10 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_11 = L_10->___byte_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_12 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_13 = L_12.___register;
		uint8_t L_14 = L_13.___byte_0;
		if ((!(((uint32_t)L_11) == ((uint32_t)L_14))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_15 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_16 = L_15->___byte_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_17 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_18 = L_17.___register;
		uint8_t L_19 = L_18.___byte_1;
		if ((!(((uint32_t)L_16) == ((uint32_t)L_19))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_20 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_21 = L_20->___byte_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_22 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_23 = L_22.___register;
		uint8_t L_24 = L_23.___byte_2;
		if ((!(((uint32_t)L_21) == ((uint32_t)L_24))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_25 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_26 = L_25->___byte_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_27 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_28 = L_27.___register;
		uint8_t L_29 = L_28.___byte_3;
		if ((!(((uint32_t)L_26) == ((uint32_t)L_29))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_30 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_31 = L_30->___byte_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_32 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_33 = L_32.___register;
		uint8_t L_34 = L_33.___byte_4;
		if ((!(((uint32_t)L_31) == ((uint32_t)L_34))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_35 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_36 = L_35->___byte_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_37 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_38 = L_37.___register;
		uint8_t L_39 = L_38.___byte_5;
		if ((!(((uint32_t)L_36) == ((uint32_t)L_39))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_40 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_41 = L_40->___byte_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_42 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_43 = L_42.___register;
		uint8_t L_44 = L_43.___byte_6;
		if ((!(((uint32_t)L_41) == ((uint32_t)L_44))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_45 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_46 = L_45->___byte_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_47 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_48 = L_47.___register;
		uint8_t L_49 = L_48.___byte_7;
		if ((!(((uint32_t)L_46) == ((uint32_t)L_49))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_50 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_51 = L_50->___byte_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_52 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_53 = L_52.___register;
		uint8_t L_54 = L_53.___byte_8;
		if ((!(((uint32_t)L_51) == ((uint32_t)L_54))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_55 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_56 = L_55->___byte_9;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_57 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_58 = L_57.___register;
		uint8_t L_59 = L_58.___byte_9;
		if ((!(((uint32_t)L_56) == ((uint32_t)L_59))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_60 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_61 = L_60->___byte_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_62 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_63 = L_62.___register;
		uint8_t L_64 = L_63.___byte_10;
		if ((!(((uint32_t)L_61) == ((uint32_t)L_64))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_65 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_66 = L_65->___byte_11;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_67 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_68 = L_67.___register;
		uint8_t L_69 = L_68.___byte_11;
		if ((!(((uint32_t)L_66) == ((uint32_t)L_69))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_70 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_71 = L_70->___byte_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_72 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_73 = L_72.___register;
		uint8_t L_74 = L_73.___byte_12;
		if ((!(((uint32_t)L_71) == ((uint32_t)L_74))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_75 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_76 = L_75->___byte_13;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_77 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_78 = L_77.___register;
		uint8_t L_79 = L_78.___byte_13;
		if ((!(((uint32_t)L_76) == ((uint32_t)L_79))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_80 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_81 = L_80->___byte_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_82 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_83 = L_82.___register;
		uint8_t L_84 = L_83.___byte_14;
		if ((!(((uint32_t)L_81) == ((uint32_t)L_84))))
		{
			goto IL_01ee;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_85 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t L_86 = L_85->___byte_15;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_87 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_88 = L_87.___register;
		uint8_t L_89 = L_88.___byte_15;
		return (bool)((((int32_t)L_86) == ((int32_t)L_89))? 1 : 0);
	}

IL_01ee:
	{
		return (bool)0;
	}

IL_01f0:
	{
		bool L_90 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_90)
		{
			goto IL_03af;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_91 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_92 = L_91->___sbyte_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_93 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_94 = L_93.___register;
		int8_t L_95 = L_94.___sbyte_0;
		if ((!(((uint32_t)L_92) == ((uint32_t)L_95))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_96 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_97 = L_96->___sbyte_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_98 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_99 = L_98.___register;
		int8_t L_100 = L_99.___sbyte_1;
		if ((!(((uint32_t)L_97) == ((uint32_t)L_100))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_101 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_102 = L_101->___sbyte_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_103 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_104 = L_103.___register;
		int8_t L_105 = L_104.___sbyte_2;
		if ((!(((uint32_t)L_102) == ((uint32_t)L_105))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_106 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_107 = L_106->___sbyte_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_108 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_109 = L_108.___register;
		int8_t L_110 = L_109.___sbyte_3;
		if ((!(((uint32_t)L_107) == ((uint32_t)L_110))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_111 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_112 = L_111->___sbyte_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_113 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_114 = L_113.___register;
		int8_t L_115 = L_114.___sbyte_4;
		if ((!(((uint32_t)L_112) == ((uint32_t)L_115))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_116 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_117 = L_116->___sbyte_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_118 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_119 = L_118.___register;
		int8_t L_120 = L_119.___sbyte_5;
		if ((!(((uint32_t)L_117) == ((uint32_t)L_120))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_121 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_122 = L_121->___sbyte_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_123 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_124 = L_123.___register;
		int8_t L_125 = L_124.___sbyte_6;
		if ((!(((uint32_t)L_122) == ((uint32_t)L_125))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_126 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_127 = L_126->___sbyte_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_128 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_129 = L_128.___register;
		int8_t L_130 = L_129.___sbyte_7;
		if ((!(((uint32_t)L_127) == ((uint32_t)L_130))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_131 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_132 = L_131->___sbyte_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_133 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_134 = L_133.___register;
		int8_t L_135 = L_134.___sbyte_8;
		if ((!(((uint32_t)L_132) == ((uint32_t)L_135))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_136 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_137 = L_136->___sbyte_9;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_138 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_139 = L_138.___register;
		int8_t L_140 = L_139.___sbyte_9;
		if ((!(((uint32_t)L_137) == ((uint32_t)L_140))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_141 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_142 = L_141->___sbyte_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_143 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_144 = L_143.___register;
		int8_t L_145 = L_144.___sbyte_10;
		if ((!(((uint32_t)L_142) == ((uint32_t)L_145))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_146 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_147 = L_146->___sbyte_11;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_148 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_149 = L_148.___register;
		int8_t L_150 = L_149.___sbyte_11;
		if ((!(((uint32_t)L_147) == ((uint32_t)L_150))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_151 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_152 = L_151->___sbyte_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_153 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_154 = L_153.___register;
		int8_t L_155 = L_154.___sbyte_12;
		if ((!(((uint32_t)L_152) == ((uint32_t)L_155))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_156 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_157 = L_156->___sbyte_13;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_158 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_159 = L_158.___register;
		int8_t L_160 = L_159.___sbyte_13;
		if ((!(((uint32_t)L_157) == ((uint32_t)L_160))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_161 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_162 = L_161->___sbyte_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_163 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_164 = L_163.___register;
		int8_t L_165 = L_164.___sbyte_14;
		if ((!(((uint32_t)L_162) == ((uint32_t)L_165))))
		{
			goto IL_03ad;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_166 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t L_167 = L_166->___sbyte_15;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_168 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_169 = L_168.___register;
		int8_t L_170 = L_169.___sbyte_15;
		return (bool)((((int32_t)L_167) == ((int32_t)L_170))? 1 : 0);
	}

IL_03ad:
	{
		return (bool)0;
	}

IL_03af:
	{
		bool L_171 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_171)
		{
			goto IL_0496;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_172 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_173 = L_172->___uint16_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_174 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_175 = L_174.___register;
		uint16_t L_176 = L_175.___uint16_0;
		if ((!(((uint32_t)L_173) == ((uint32_t)L_176))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_177 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_178 = L_177->___uint16_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_179 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_180 = L_179.___register;
		uint16_t L_181 = L_180.___uint16_1;
		if ((!(((uint32_t)L_178) == ((uint32_t)L_181))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_182 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_183 = L_182->___uint16_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_184 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_185 = L_184.___register;
		uint16_t L_186 = L_185.___uint16_2;
		if ((!(((uint32_t)L_183) == ((uint32_t)L_186))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_187 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_188 = L_187->___uint16_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_189 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_190 = L_189.___register;
		uint16_t L_191 = L_190.___uint16_3;
		if ((!(((uint32_t)L_188) == ((uint32_t)L_191))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_192 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_193 = L_192->___uint16_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_194 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_195 = L_194.___register;
		uint16_t L_196 = L_195.___uint16_4;
		if ((!(((uint32_t)L_193) == ((uint32_t)L_196))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_197 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_198 = L_197->___uint16_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_199 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_200 = L_199.___register;
		uint16_t L_201 = L_200.___uint16_5;
		if ((!(((uint32_t)L_198) == ((uint32_t)L_201))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_202 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_203 = L_202->___uint16_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_204 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_205 = L_204.___register;
		uint16_t L_206 = L_205.___uint16_6;
		if ((!(((uint32_t)L_203) == ((uint32_t)L_206))))
		{
			goto IL_0494;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_207 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t L_208 = L_207->___uint16_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_209 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_210 = L_209.___register;
		uint16_t L_211 = L_210.___uint16_7;
		return (bool)((((int32_t)L_208) == ((int32_t)L_211))? 1 : 0);
	}

IL_0494:
	{
		return (bool)0;
	}

IL_0496:
	{
		bool L_212 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_212)
		{
			goto IL_057d;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_213 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_214 = L_213->___int16_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_215 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_216 = L_215.___register;
		int16_t L_217 = L_216.___int16_0;
		if ((!(((uint32_t)L_214) == ((uint32_t)L_217))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_218 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_219 = L_218->___int16_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_220 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_221 = L_220.___register;
		int16_t L_222 = L_221.___int16_1;
		if ((!(((uint32_t)L_219) == ((uint32_t)L_222))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_223 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_224 = L_223->___int16_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_225 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_226 = L_225.___register;
		int16_t L_227 = L_226.___int16_2;
		if ((!(((uint32_t)L_224) == ((uint32_t)L_227))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_228 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_229 = L_228->___int16_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_230 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_231 = L_230.___register;
		int16_t L_232 = L_231.___int16_3;
		if ((!(((uint32_t)L_229) == ((uint32_t)L_232))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_233 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_234 = L_233->___int16_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_235 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_236 = L_235.___register;
		int16_t L_237 = L_236.___int16_4;
		if ((!(((uint32_t)L_234) == ((uint32_t)L_237))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_238 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_239 = L_238->___int16_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_240 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_241 = L_240.___register;
		int16_t L_242 = L_241.___int16_5;
		if ((!(((uint32_t)L_239) == ((uint32_t)L_242))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_243 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_244 = L_243->___int16_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_245 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_246 = L_245.___register;
		int16_t L_247 = L_246.___int16_6;
		if ((!(((uint32_t)L_244) == ((uint32_t)L_247))))
		{
			goto IL_057b;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_248 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t L_249 = L_248->___int16_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_250 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_251 = L_250.___register;
		int16_t L_252 = L_251.___int16_7;
		return (bool)((((int32_t)L_249) == ((int32_t)L_252))? 1 : 0);
	}

IL_057b:
	{
		return (bool)0;
	}

IL_057d:
	{
		bool L_253 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_253)
		{
			goto IL_05fb;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_254 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t L_255 = L_254->___uint32_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_256 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_257 = L_256.___register;
		uint32_t L_258 = L_257.___uint32_0;
		if ((!(((uint32_t)L_255) == ((uint32_t)L_258))))
		{
			goto IL_05f9;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_259 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t L_260 = L_259->___uint32_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_261 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_262 = L_261.___register;
		uint32_t L_263 = L_262.___uint32_1;
		if ((!(((uint32_t)L_260) == ((uint32_t)L_263))))
		{
			goto IL_05f9;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_264 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t L_265 = L_264->___uint32_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_266 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_267 = L_266.___register;
		uint32_t L_268 = L_267.___uint32_2;
		if ((!(((uint32_t)L_265) == ((uint32_t)L_268))))
		{
			goto IL_05f9;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_269 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t L_270 = L_269->___uint32_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_271 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_272 = L_271.___register;
		uint32_t L_273 = L_272.___uint32_3;
		return (bool)((((int32_t)L_270) == ((int32_t)L_273))? 1 : 0);
	}

IL_05f9:
	{
		return (bool)0;
	}

IL_05fb:
	{
		bool L_274 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_274)
		{
			goto IL_0679;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_275 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t L_276 = L_275->___int32_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_277 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_278 = L_277.___register;
		int32_t L_279 = L_278.___int32_0;
		if ((!(((uint32_t)L_276) == ((uint32_t)L_279))))
		{
			goto IL_0677;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_280 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t L_281 = L_280->___int32_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_282 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_283 = L_282.___register;
		int32_t L_284 = L_283.___int32_1;
		if ((!(((uint32_t)L_281) == ((uint32_t)L_284))))
		{
			goto IL_0677;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_285 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t L_286 = L_285->___int32_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_287 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_288 = L_287.___register;
		int32_t L_289 = L_288.___int32_2;
		if ((!(((uint32_t)L_286) == ((uint32_t)L_289))))
		{
			goto IL_0677;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_290 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t L_291 = L_290->___int32_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_292 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_293 = L_292.___register;
		int32_t L_294 = L_293.___int32_3;
		return (bool)((((int32_t)L_291) == ((int32_t)L_294))? 1 : 0);
	}

IL_0677:
	{
		return (bool)0;
	}

IL_0679:
	{
		bool L_295 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_295)
		{
			goto IL_06c7;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_296 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_297 = L_296->___uint64_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_298 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_299 = L_298.___register;
		uint64_t L_300 = L_299.___uint64_0;
		if ((!(((uint64_t)L_297) == ((uint64_t)L_300))))
		{
			goto IL_06c5;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_301 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t L_302 = L_301->___uint64_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_303 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_304 = L_303.___register;
		uint64_t L_305 = L_304.___uint64_1;
		return (bool)((((int64_t)L_302) == ((int64_t)L_305))? 1 : 0);
	}

IL_06c5:
	{
		return (bool)0;
	}

IL_06c7:
	{
		bool L_306 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_306)
		{
			goto IL_0715;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_307 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t L_308 = L_307->___int64_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_309 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_310 = L_309.___register;
		int64_t L_311 = L_310.___int64_0;
		if ((!(((uint64_t)L_308) == ((uint64_t)L_311))))
		{
			goto IL_0713;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_312 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t L_313 = L_312->___int64_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_314 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_315 = L_314.___register;
		int64_t L_316 = L_315.___int64_1;
		return (bool)((((int64_t)L_313) == ((int64_t)L_316))? 1 : 0);
	}

IL_0713:
	{
		return (bool)0;
	}

IL_0715:
	{
		bool L_317 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_317)
		{
			goto IL_0793;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_318 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float L_319 = L_318->___single_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_320 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_321 = L_320.___register;
		float L_322 = L_321.___single_0;
		if ((!(((float)L_319) == ((float)L_322))))
		{
			goto IL_0791;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_323 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float L_324 = L_323->___single_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_325 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_326 = L_325.___register;
		float L_327 = L_326.___single_1;
		if ((!(((float)L_324) == ((float)L_327))))
		{
			goto IL_0791;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_328 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float L_329 = L_328->___single_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_330 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_331 = L_330.___register;
		float L_332 = L_331.___single_2;
		if ((!(((float)L_329) == ((float)L_332))))
		{
			goto IL_0791;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_333 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float L_334 = L_333->___single_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_335 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_336 = L_335.___register;
		float L_337 = L_336.___single_3;
		return (bool)((((float)L_334) == ((float)L_337))? 1 : 0);
	}

IL_0791:
	{
		return (bool)0;
	}

IL_0793:
	{
		bool L_338 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_338)
		{
			goto IL_07e1;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_339 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double L_340 = L_339->___double_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_341 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_342 = L_341.___register;
		double L_343 = L_342.___double_0;
		if ((!(((double)L_340) == ((double)L_343))))
		{
			goto IL_07df;
		}
	}
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_344 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double L_345 = L_344->___double_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_346 = ___0_other;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_347 = L_346.___register;
		double L_348 = L_347.___double_1;
		return (bool)((((double)L_345) == ((double)L_348))? 1 : 0);
	}

IL_07df:
	{
		return (bool)0;
	}

IL_07e1:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_349 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_349, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_349, method);
	}
}
IL2CPP_EXTERN_C  bool Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8_AdjustorThunk (RuntimeObject* __this, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_other, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	bool _returnValue;
	_returnValue = Vector_1_Equals_mBC248D1BFF0E4CEA6585C0F10707B1843A4502E8(_thisAdjusted, ___0_other, method);
	return _returnValue;
}
// Method Definition Index: 8065
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	CHECKED_LOCAL(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_15 = L_4;
	const Il2CppFullySharedGenericStruct L_26 = L_4;
	const Il2CppFullySharedGenericStruct L_37 = L_4;
	const Il2CppFullySharedGenericStruct L_48 = L_4;
	const Il2CppFullySharedGenericStruct L_59 = L_4;
	const Il2CppFullySharedGenericStruct L_70 = L_4;
	const Il2CppFullySharedGenericStruct L_81 = L_4;
	const Il2CppFullySharedGenericStruct L_92 = L_4;
	const Il2CppFullySharedGenericStruct L_103 = L_4;
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	uint8_t V_2 = 0x0;
	int32_t V_3 = 0;
	int8_t V_4 = 0x0;
	int32_t V_5 = 0;
	uint16_t V_6 = 0;
	int32_t V_7 = 0;
	int16_t V_8 = 0;
	int32_t V_9 = 0;
	uint32_t V_10 = 0;
	int32_t V_11 = 0;
	int32_t V_12 = 0;
	int32_t V_13 = 0;
	uint64_t V_14 = 0;
	int32_t V_15 = 0;
	int64_t V_16 = 0;
	int32_t V_17 = 0;
	float V_18 = 0.0f;
	int32_t V_19 = 0;
	double V_20 = 0.0;
	{
		V_0 = 0;
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_034a;
		}
	}
	{
		bool L_1 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_1)
		{
			goto IL_0059;
		}
	}
	{
		V_1 = 0;
		goto IL_004f;
	}

IL_002b:
	{
		int32_t L_2 = V_0;
		int32_t L_3 = V_1;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_3, (Il2CppFullySharedGenericStruct*)L_4);
		uint8_t L_5;
		il2cpp_codegen_box_unbox(L_4, (&L_5), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		V_2 = L_5;
		int32_t L_6;
		L_6 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678((&V_2), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_7;
		L_7 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_2, L_6, NULL);
		V_0 = L_7;
		int32_t L_8 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_8, 1));
	}

IL_004f:
	{
		int32_t L_9 = V_1;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_10;
		L_10 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_9) < ((int32_t)L_10)))
		{
			goto IL_002b;
		}
	}
	{
		int32_t L_11 = V_0;
		return L_11;
	}

IL_0059:
	{
		bool L_12 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_12)
		{
			goto IL_00a7;
		}
	}
	{
		V_3 = 0;
		goto IL_009d;
	}

IL_0078:
	{
		int32_t L_13 = V_0;
		int32_t L_14 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_14, (Il2CppFullySharedGenericStruct*)L_15);
		int8_t L_16;
		il2cpp_codegen_box_unbox(L_15, (&L_16), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		V_4 = L_16;
		int32_t L_17;
		L_17 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF((&V_4), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_18;
		L_18 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_13, L_17, NULL);
		V_0 = L_18;
		int32_t L_19 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_009d:
	{
		int32_t L_20 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_21;
		L_21 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_20) < ((int32_t)L_21)))
		{
			goto IL_0078;
		}
	}
	{
		int32_t L_22 = V_0;
		return L_22;
	}

IL_00a7:
	{
		bool L_23 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_23)
		{
			goto IL_00fa;
		}
	}
	{
		V_5 = 0;
		goto IL_00ef;
	}

IL_00c7:
	{
		int32_t L_24 = V_0;
		int32_t L_25 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_25, (Il2CppFullySharedGenericStruct*)L_26);
		uint16_t L_27;
		il2cpp_codegen_box_unbox(L_26, (&L_27), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		V_6 = L_27;
		int32_t L_28;
		L_28 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200((&V_6), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_29;
		L_29 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_24, L_28, NULL);
		V_0 = L_29;
		int32_t L_30 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_00ef:
	{
		int32_t L_31 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_32;
		L_32 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_31) < ((int32_t)L_32)))
		{
			goto IL_00c7;
		}
	}
	{
		int32_t L_33 = V_0;
		return L_33;
	}

IL_00fa:
	{
		bool L_34 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_34)
		{
			goto IL_014d;
		}
	}
	{
		V_7 = 0;
		goto IL_0142;
	}

IL_011a:
	{
		int32_t L_35 = V_0;
		int32_t L_36 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_36, (Il2CppFullySharedGenericStruct*)L_37);
		int16_t L_38;
		il2cpp_codegen_box_unbox(L_37, (&L_38), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		V_8 = L_38;
		int32_t L_39;
		L_39 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1((&V_8), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_40;
		L_40 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_35, L_39, NULL);
		V_0 = L_40;
		int32_t L_41 = V_7;
		V_7 = ((int32_t)il2cpp_codegen_add(L_41, 1));
	}

IL_0142:
	{
		int32_t L_42 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_43;
		L_43 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_42) < ((int32_t)L_43)))
		{
			goto IL_011a;
		}
	}
	{
		int32_t L_44 = V_0;
		return L_44;
	}

IL_014d:
	{
		bool L_45 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_45)
		{
			goto IL_01a0;
		}
	}
	{
		V_9 = 0;
		goto IL_0195;
	}

IL_016d:
	{
		int32_t L_46 = V_0;
		int32_t L_47 = V_9;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_47, (Il2CppFullySharedGenericStruct*)L_48);
		uint32_t L_49;
		il2cpp_codegen_box_unbox(L_48, (&L_49), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		V_10 = L_49;
		int32_t L_50;
		L_50 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC((&V_10), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_51;
		L_51 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_46, L_50, NULL);
		V_0 = L_51;
		int32_t L_52 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_52, 1));
	}

IL_0195:
	{
		int32_t L_53 = V_9;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_54;
		L_54 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_53) < ((int32_t)L_54)))
		{
			goto IL_016d;
		}
	}
	{
		int32_t L_55 = V_0;
		return L_55;
	}

IL_01a0:
	{
		bool L_56 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_56)
		{
			goto IL_01f3;
		}
	}
	{
		V_11 = 0;
		goto IL_01e8;
	}

IL_01c0:
	{
		int32_t L_57 = V_0;
		int32_t L_58 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_58, (Il2CppFullySharedGenericStruct*)L_59);
		int32_t L_60;
		il2cpp_codegen_box_unbox(L_59, (&L_60), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		V_12 = L_60;
		int32_t L_61;
		L_61 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295((&V_12), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_62;
		L_62 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_57, L_61, NULL);
		V_0 = L_62;
		int32_t L_63 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_63, 1));
	}

IL_01e8:
	{
		int32_t L_64 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_65;
		L_65 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_64) < ((int32_t)L_65)))
		{
			goto IL_01c0;
		}
	}
	{
		int32_t L_66 = V_0;
		return L_66;
	}

IL_01f3:
	{
		bool L_67 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_67)
		{
			goto IL_0246;
		}
	}
	{
		V_13 = 0;
		goto IL_023b;
	}

IL_0213:
	{
		int32_t L_68 = V_0;
		int32_t L_69 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_69, (Il2CppFullySharedGenericStruct*)L_70);
		uint64_t L_71;
		il2cpp_codegen_box_unbox(L_70, (&L_71), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		V_14 = L_71;
		int32_t L_72;
		L_72 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92((&V_14), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_73;
		L_73 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_68, L_72, NULL);
		V_0 = L_73;
		int32_t L_74 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_74, 1));
	}

IL_023b:
	{
		int32_t L_75 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_76;
		L_76 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_75) < ((int32_t)L_76)))
		{
			goto IL_0213;
		}
	}
	{
		int32_t L_77 = V_0;
		return L_77;
	}

IL_0246:
	{
		bool L_78 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_78)
		{
			goto IL_0299;
		}
	}
	{
		V_15 = 0;
		goto IL_028e;
	}

IL_0266:
	{
		int32_t L_79 = V_0;
		int32_t L_80 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_80, (Il2CppFullySharedGenericStruct*)L_81);
		int64_t L_82;
		il2cpp_codegen_box_unbox(L_81, (&L_82), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		V_16 = L_82;
		int32_t L_83;
		L_83 = Int64_GetHashCode_mDB050BE2AC244D92B14D1DF725AAD279CDC48496((&V_16), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_84;
		L_84 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_79, L_83, NULL);
		V_0 = L_84;
		int32_t L_85 = V_15;
		V_15 = ((int32_t)il2cpp_codegen_add(L_85, 1));
	}

IL_028e:
	{
		int32_t L_86 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_87;
		L_87 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_86) < ((int32_t)L_87)))
		{
			goto IL_0266;
		}
	}
	{
		int32_t L_88 = V_0;
		return L_88;
	}

IL_0299:
	{
		bool L_89 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_89)
		{
			goto IL_02ec;
		}
	}
	{
		V_17 = 0;
		goto IL_02e1;
	}

IL_02b9:
	{
		int32_t L_90 = V_0;
		int32_t L_91 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_91, (Il2CppFullySharedGenericStruct*)L_92);
		float L_93;
		il2cpp_codegen_box_unbox(L_92, (&L_93), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		V_18 = L_93;
		int32_t L_94;
		L_94 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2((&V_18), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_95;
		L_95 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_90, L_94, NULL);
		V_0 = L_95;
		int32_t L_96 = V_17;
		V_17 = ((int32_t)il2cpp_codegen_add(L_96, 1));
	}

IL_02e1:
	{
		int32_t L_97 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_98;
		L_98 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_97) < ((int32_t)L_98)))
		{
			goto IL_02b9;
		}
	}
	{
		int32_t L_99 = V_0;
		return L_99;
	}

IL_02ec:
	{
		bool L_100 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_100)
		{
			goto IL_033f;
		}
	}
	{
		V_19 = 0;
		goto IL_0334;
	}

IL_030c:
	{
		int32_t L_101 = V_0;
		int32_t L_102 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_102, (Il2CppFullySharedGenericStruct*)L_103);
		double L_104;
		il2cpp_codegen_box_unbox(L_103, (&L_104), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		V_20 = L_104;
		int32_t L_105;
		L_105 = Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline((&V_20), NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_106;
		L_106 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_101, L_105, NULL);
		V_0 = L_106;
		int32_t L_107 = V_19;
		V_19 = ((int32_t)il2cpp_codegen_add(L_107, 1));
	}

IL_0334:
	{
		int32_t L_108 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_109;
		L_109 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_108) < ((int32_t)L_109)))
		{
			goto IL_030c;
		}
	}
	{
		int32_t L_110 = V_0;
		return L_110;
	}

IL_033f:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_111 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_111, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_111, method);
	}

IL_034a:
	{
		bool L_112 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_112)
		{
			goto IL_04da;
		}
	}
	{
		int32_t L_113 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_114 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_115 = (uint8_t*)(&L_114->___byte_0);
		int32_t L_116;
		L_116 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_115, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_117;
		L_117 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_113, L_116, NULL);
		V_0 = L_117;
		int32_t L_118 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_119 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_120 = (uint8_t*)(&L_119->___byte_1);
		int32_t L_121;
		L_121 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_120, NULL);
		int32_t L_122;
		L_122 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_118, L_121, NULL);
		V_0 = L_122;
		int32_t L_123 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_124 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_125 = (uint8_t*)(&L_124->___byte_2);
		int32_t L_126;
		L_126 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_125, NULL);
		int32_t L_127;
		L_127 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_123, L_126, NULL);
		V_0 = L_127;
		int32_t L_128 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_129 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_130 = (uint8_t*)(&L_129->___byte_3);
		int32_t L_131;
		L_131 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_130, NULL);
		int32_t L_132;
		L_132 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_128, L_131, NULL);
		V_0 = L_132;
		int32_t L_133 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_134 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_135 = (uint8_t*)(&L_134->___byte_4);
		int32_t L_136;
		L_136 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_135, NULL);
		int32_t L_137;
		L_137 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_133, L_136, NULL);
		V_0 = L_137;
		int32_t L_138 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_139 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_140 = (uint8_t*)(&L_139->___byte_5);
		int32_t L_141;
		L_141 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_140, NULL);
		int32_t L_142;
		L_142 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_138, L_141, NULL);
		V_0 = L_142;
		int32_t L_143 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_144 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_145 = (uint8_t*)(&L_144->___byte_6);
		int32_t L_146;
		L_146 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_145, NULL);
		int32_t L_147;
		L_147 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_143, L_146, NULL);
		V_0 = L_147;
		int32_t L_148 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_149 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_150 = (uint8_t*)(&L_149->___byte_7);
		int32_t L_151;
		L_151 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_150, NULL);
		int32_t L_152;
		L_152 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_148, L_151, NULL);
		V_0 = L_152;
		int32_t L_153 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_154 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_155 = (uint8_t*)(&L_154->___byte_8);
		int32_t L_156;
		L_156 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_155, NULL);
		int32_t L_157;
		L_157 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_153, L_156, NULL);
		V_0 = L_157;
		int32_t L_158 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_159 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_160 = (uint8_t*)(&L_159->___byte_9);
		int32_t L_161;
		L_161 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_160, NULL);
		int32_t L_162;
		L_162 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_158, L_161, NULL);
		V_0 = L_162;
		int32_t L_163 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_164 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_165 = (uint8_t*)(&L_164->___byte_10);
		int32_t L_166;
		L_166 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_165, NULL);
		int32_t L_167;
		L_167 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_163, L_166, NULL);
		V_0 = L_167;
		int32_t L_168 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_169 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_170 = (uint8_t*)(&L_169->___byte_11);
		int32_t L_171;
		L_171 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_170, NULL);
		int32_t L_172;
		L_172 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_168, L_171, NULL);
		V_0 = L_172;
		int32_t L_173 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_174 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_175 = (uint8_t*)(&L_174->___byte_12);
		int32_t L_176;
		L_176 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_175, NULL);
		int32_t L_177;
		L_177 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_173, L_176, NULL);
		V_0 = L_177;
		int32_t L_178 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_179 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_180 = (uint8_t*)(&L_179->___byte_13);
		int32_t L_181;
		L_181 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_180, NULL);
		int32_t L_182;
		L_182 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_178, L_181, NULL);
		V_0 = L_182;
		int32_t L_183 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_184 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_185 = (uint8_t*)(&L_184->___byte_14);
		int32_t L_186;
		L_186 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_185, NULL);
		int32_t L_187;
		L_187 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_183, L_186, NULL);
		V_0 = L_187;
		int32_t L_188 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_189 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint8_t* L_190 = (uint8_t*)(&L_189->___byte_15);
		int32_t L_191;
		L_191 = Byte_GetHashCode_mB42A844E310593D124CE92EBA90F3755C9B10678(L_190, NULL);
		int32_t L_192;
		L_192 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_188, L_191, NULL);
		V_0 = L_192;
		int32_t L_193 = V_0;
		return L_193;
	}

IL_04da:
	{
		bool L_194 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_194)
		{
			goto IL_066a;
		}
	}
	{
		int32_t L_195 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_196 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_197 = (int8_t*)(&L_196->___sbyte_0);
		int32_t L_198;
		L_198 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_197, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_199;
		L_199 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_195, L_198, NULL);
		V_0 = L_199;
		int32_t L_200 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_201 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_202 = (int8_t*)(&L_201->___sbyte_1);
		int32_t L_203;
		L_203 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_202, NULL);
		int32_t L_204;
		L_204 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_200, L_203, NULL);
		V_0 = L_204;
		int32_t L_205 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_206 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_207 = (int8_t*)(&L_206->___sbyte_2);
		int32_t L_208;
		L_208 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_207, NULL);
		int32_t L_209;
		L_209 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_205, L_208, NULL);
		V_0 = L_209;
		int32_t L_210 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_211 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_212 = (int8_t*)(&L_211->___sbyte_3);
		int32_t L_213;
		L_213 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_212, NULL);
		int32_t L_214;
		L_214 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_210, L_213, NULL);
		V_0 = L_214;
		int32_t L_215 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_216 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_217 = (int8_t*)(&L_216->___sbyte_4);
		int32_t L_218;
		L_218 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_217, NULL);
		int32_t L_219;
		L_219 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_215, L_218, NULL);
		V_0 = L_219;
		int32_t L_220 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_221 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_222 = (int8_t*)(&L_221->___sbyte_5);
		int32_t L_223;
		L_223 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_222, NULL);
		int32_t L_224;
		L_224 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_220, L_223, NULL);
		V_0 = L_224;
		int32_t L_225 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_226 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_227 = (int8_t*)(&L_226->___sbyte_6);
		int32_t L_228;
		L_228 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_227, NULL);
		int32_t L_229;
		L_229 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_225, L_228, NULL);
		V_0 = L_229;
		int32_t L_230 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_231 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_232 = (int8_t*)(&L_231->___sbyte_7);
		int32_t L_233;
		L_233 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_232, NULL);
		int32_t L_234;
		L_234 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_230, L_233, NULL);
		V_0 = L_234;
		int32_t L_235 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_236 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_237 = (int8_t*)(&L_236->___sbyte_8);
		int32_t L_238;
		L_238 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_237, NULL);
		int32_t L_239;
		L_239 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_235, L_238, NULL);
		V_0 = L_239;
		int32_t L_240 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_241 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_242 = (int8_t*)(&L_241->___sbyte_9);
		int32_t L_243;
		L_243 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_242, NULL);
		int32_t L_244;
		L_244 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_240, L_243, NULL);
		V_0 = L_244;
		int32_t L_245 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_246 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_247 = (int8_t*)(&L_246->___sbyte_10);
		int32_t L_248;
		L_248 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_247, NULL);
		int32_t L_249;
		L_249 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_245, L_248, NULL);
		V_0 = L_249;
		int32_t L_250 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_251 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_252 = (int8_t*)(&L_251->___sbyte_11);
		int32_t L_253;
		L_253 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_252, NULL);
		int32_t L_254;
		L_254 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_250, L_253, NULL);
		V_0 = L_254;
		int32_t L_255 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_256 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_257 = (int8_t*)(&L_256->___sbyte_12);
		int32_t L_258;
		L_258 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_257, NULL);
		int32_t L_259;
		L_259 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_255, L_258, NULL);
		V_0 = L_259;
		int32_t L_260 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_261 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_262 = (int8_t*)(&L_261->___sbyte_13);
		int32_t L_263;
		L_263 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_262, NULL);
		int32_t L_264;
		L_264 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_260, L_263, NULL);
		V_0 = L_264;
		int32_t L_265 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_266 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_267 = (int8_t*)(&L_266->___sbyte_14);
		int32_t L_268;
		L_268 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_267, NULL);
		int32_t L_269;
		L_269 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_265, L_268, NULL);
		V_0 = L_269;
		int32_t L_270 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_271 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int8_t* L_272 = (int8_t*)(&L_271->___sbyte_15);
		int32_t L_273;
		L_273 = SByte_GetHashCode_mE61E9B0D1D93EF3E4E2B6282FF940FFA2E471FFF(L_272, NULL);
		int32_t L_274;
		L_274 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_270, L_273, NULL);
		V_0 = L_274;
		int32_t L_275 = V_0;
		return L_275;
	}

IL_066a:
	{
		bool L_276 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_276)
		{
			goto IL_0742;
		}
	}
	{
		int32_t L_277 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_278 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_279 = (uint16_t*)(&L_278->___uint16_0);
		int32_t L_280;
		L_280 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_279, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_281;
		L_281 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_277, L_280, NULL);
		V_0 = L_281;
		int32_t L_282 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_283 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_284 = (uint16_t*)(&L_283->___uint16_1);
		int32_t L_285;
		L_285 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_284, NULL);
		int32_t L_286;
		L_286 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_282, L_285, NULL);
		V_0 = L_286;
		int32_t L_287 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_288 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_289 = (uint16_t*)(&L_288->___uint16_2);
		int32_t L_290;
		L_290 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_289, NULL);
		int32_t L_291;
		L_291 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_287, L_290, NULL);
		V_0 = L_291;
		int32_t L_292 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_293 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_294 = (uint16_t*)(&L_293->___uint16_3);
		int32_t L_295;
		L_295 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_294, NULL);
		int32_t L_296;
		L_296 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_292, L_295, NULL);
		V_0 = L_296;
		int32_t L_297 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_298 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_299 = (uint16_t*)(&L_298->___uint16_4);
		int32_t L_300;
		L_300 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_299, NULL);
		int32_t L_301;
		L_301 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_297, L_300, NULL);
		V_0 = L_301;
		int32_t L_302 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_303 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_304 = (uint16_t*)(&L_303->___uint16_5);
		int32_t L_305;
		L_305 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_304, NULL);
		int32_t L_306;
		L_306 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_302, L_305, NULL);
		V_0 = L_306;
		int32_t L_307 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_308 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_309 = (uint16_t*)(&L_308->___uint16_6);
		int32_t L_310;
		L_310 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_309, NULL);
		int32_t L_311;
		L_311 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_307, L_310, NULL);
		V_0 = L_311;
		int32_t L_312 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_313 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint16_t* L_314 = (uint16_t*)(&L_313->___uint16_7);
		int32_t L_315;
		L_315 = UInt16_GetHashCode_m534E5103D0DA9C6FCED4F2F007993D3E38165200(L_314, NULL);
		int32_t L_316;
		L_316 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_312, L_315, NULL);
		V_0 = L_316;
		int32_t L_317 = V_0;
		return L_317;
	}

IL_0742:
	{
		bool L_318 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_318)
		{
			goto IL_081a;
		}
	}
	{
		int32_t L_319 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_320 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_321 = (int16_t*)(&L_320->___int16_0);
		int32_t L_322;
		L_322 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_321, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_323;
		L_323 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_319, L_322, NULL);
		V_0 = L_323;
		int32_t L_324 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_325 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_326 = (int16_t*)(&L_325->___int16_1);
		int32_t L_327;
		L_327 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_326, NULL);
		int32_t L_328;
		L_328 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_324, L_327, NULL);
		V_0 = L_328;
		int32_t L_329 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_330 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_331 = (int16_t*)(&L_330->___int16_2);
		int32_t L_332;
		L_332 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_331, NULL);
		int32_t L_333;
		L_333 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_329, L_332, NULL);
		V_0 = L_333;
		int32_t L_334 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_335 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_336 = (int16_t*)(&L_335->___int16_3);
		int32_t L_337;
		L_337 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_336, NULL);
		int32_t L_338;
		L_338 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_334, L_337, NULL);
		V_0 = L_338;
		int32_t L_339 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_340 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_341 = (int16_t*)(&L_340->___int16_4);
		int32_t L_342;
		L_342 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_341, NULL);
		int32_t L_343;
		L_343 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_339, L_342, NULL);
		V_0 = L_343;
		int32_t L_344 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_345 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_346 = (int16_t*)(&L_345->___int16_5);
		int32_t L_347;
		L_347 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_346, NULL);
		int32_t L_348;
		L_348 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_344, L_347, NULL);
		V_0 = L_348;
		int32_t L_349 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_350 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_351 = (int16_t*)(&L_350->___int16_6);
		int32_t L_352;
		L_352 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_351, NULL);
		int32_t L_353;
		L_353 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_349, L_352, NULL);
		V_0 = L_353;
		int32_t L_354 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_355 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int16_t* L_356 = (int16_t*)(&L_355->___int16_7);
		int32_t L_357;
		L_357 = Int16_GetHashCode_mCD0A167AC8E6ACC2235F12E00C0F9BDC6ED3B6E1(L_356, NULL);
		int32_t L_358;
		L_358 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_354, L_357, NULL);
		V_0 = L_358;
		int32_t L_359 = V_0;
		return L_359;
	}

IL_081a:
	{
		bool L_360 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_360)
		{
			goto IL_0893;
		}
	}
	{
		int32_t L_361 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_362 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_363 = (uint32_t*)(&L_362->___uint32_0);
		int32_t L_364;
		L_364 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC(L_363, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_365;
		L_365 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_361, L_364, NULL);
		V_0 = L_365;
		int32_t L_366 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_367 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_368 = (uint32_t*)(&L_367->___uint32_1);
		int32_t L_369;
		L_369 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC(L_368, NULL);
		int32_t L_370;
		L_370 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_366, L_369, NULL);
		V_0 = L_370;
		int32_t L_371 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_372 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_373 = (uint32_t*)(&L_372->___uint32_2);
		int32_t L_374;
		L_374 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC(L_373, NULL);
		int32_t L_375;
		L_375 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_371, L_374, NULL);
		V_0 = L_375;
		int32_t L_376 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_377 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint32_t* L_378 = (uint32_t*)(&L_377->___uint32_3);
		int32_t L_379;
		L_379 = UInt32_GetHashCode_mB9A03A037C079ADF0E61516BECA1AB05F92266BC(L_378, NULL);
		int32_t L_380;
		L_380 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_376, L_379, NULL);
		V_0 = L_380;
		int32_t L_381 = V_0;
		return L_381;
	}

IL_0893:
	{
		bool L_382 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_382)
		{
			goto IL_090c;
		}
	}
	{
		int32_t L_383 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_384 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_385 = (int32_t*)(&L_384->___int32_0);
		int32_t L_386;
		L_386 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_385, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_387;
		L_387 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_383, L_386, NULL);
		V_0 = L_387;
		int32_t L_388 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_389 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_390 = (int32_t*)(&L_389->___int32_1);
		int32_t L_391;
		L_391 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_390, NULL);
		int32_t L_392;
		L_392 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_388, L_391, NULL);
		V_0 = L_392;
		int32_t L_393 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_394 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_395 = (int32_t*)(&L_394->___int32_2);
		int32_t L_396;
		L_396 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_395, NULL);
		int32_t L_397;
		L_397 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_393, L_396, NULL);
		V_0 = L_397;
		int32_t L_398 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_399 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int32_t* L_400 = (int32_t*)(&L_399->___int32_3);
		int32_t L_401;
		L_401 = Int32_GetHashCode_m253D60FF7527A483E91004B7A2366F13E225E295(L_400, NULL);
		int32_t L_402;
		L_402 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_398, L_401, NULL);
		V_0 = L_402;
		int32_t L_403 = V_0;
		return L_403;
	}

IL_090c:
	{
		bool L_404 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_404)
		{
			goto IL_0957;
		}
	}
	{
		int32_t L_405 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_406 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_407 = (uint64_t*)(&L_406->___uint64_0);
		int32_t L_408;
		L_408 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_407, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_409;
		L_409 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_405, L_408, NULL);
		V_0 = L_409;
		int32_t L_410 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_411 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		uint64_t* L_412 = (uint64_t*)(&L_411->___uint64_1);
		int32_t L_413;
		L_413 = UInt64_GetHashCode_m65D9FD0102B6B01BF38D986F060F0BDBC29B4F92(L_412, NULL);
		int32_t L_414;
		L_414 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_410, L_413, NULL);
		V_0 = L_414;
		int32_t L_415 = V_0;
		return L_415;
	}

IL_0957:
	{
		bool L_416 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_416)
		{
			goto IL_09a2;
		}
	}
	{
		int32_t L_417 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_418 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_419 = (int64_t*)(&L_418->___int64_0);
		int32_t L_420;
		L_420 = Int64_GetHashCode_mDB050BE2AC244D92B14D1DF725AAD279CDC48496(L_419, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_421;
		L_421 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_417, L_420, NULL);
		V_0 = L_421;
		int32_t L_422 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_423 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		int64_t* L_424 = (int64_t*)(&L_423->___int64_1);
		int32_t L_425;
		L_425 = Int64_GetHashCode_mDB050BE2AC244D92B14D1DF725AAD279CDC48496(L_424, NULL);
		int32_t L_426;
		L_426 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_422, L_425, NULL);
		V_0 = L_426;
		int32_t L_427 = V_0;
		return L_427;
	}

IL_09a2:
	{
		bool L_428 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_428)
		{
			goto IL_0a1b;
		}
	}
	{
		int32_t L_429 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_430 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_431 = (float*)(&L_430->___single_0);
		int32_t L_432;
		L_432 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2(L_431, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_433;
		L_433 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_429, L_432, NULL);
		V_0 = L_433;
		int32_t L_434 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_435 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_436 = (float*)(&L_435->___single_1);
		int32_t L_437;
		L_437 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2(L_436, NULL);
		int32_t L_438;
		L_438 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_434, L_437, NULL);
		V_0 = L_438;
		int32_t L_439 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_440 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_441 = (float*)(&L_440->___single_2);
		int32_t L_442;
		L_442 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2(L_441, NULL);
		int32_t L_443;
		L_443 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_439, L_442, NULL);
		V_0 = L_443;
		int32_t L_444 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_445 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		float* L_446 = (float*)(&L_445->___single_3);
		int32_t L_447;
		L_447 = Single_GetHashCode_mC3F1E099D1CF165C2D71FBCC5EF6A6792F9021D2(L_446, NULL);
		int32_t L_448;
		L_448 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_444, L_447, NULL);
		V_0 = L_448;
		int32_t L_449 = V_0;
		return L_449;
	}

IL_0a1b:
	{
		bool L_450 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_450)
		{
			goto IL_0a66;
		}
	}
	{
		int32_t L_451 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_452 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_453 = (double*)(&L_452->___double_0);
		int32_t L_454;
		L_454 = Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline(L_453, NULL);
		CHECKED_LOCAL_INIT(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_StaticInit,(HashHelpers_t285C6E63B4A4E8D837BDBC63DE4E2D23C85467D4_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_455;
		L_455 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_451, L_454, NULL);
		V_0 = L_455;
		int32_t L_456 = V_0;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_457 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&__this->___register);
		double* L_458 = (double*)(&L_457->___double_1);
		int32_t L_459;
		L_459 = Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline(L_458, NULL);
		int32_t L_460;
		L_460 = HashHelpers_Combine_mBE398FF248FE6B082F5E254BCD36E3B3351608D7(L_456, L_459, NULL);
		V_0 = L_460;
		int32_t L_461 = V_0;
		return L_461;
	}

IL_0a66:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_462 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_462, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_462, method);
	}
}
IL2CPP_EXTERN_C  int32_t Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	int32_t _returnValue;
	_returnValue = Vector_1_GetHashCode_m3ACEDE87318824BACAD7E8CB760798D98D37C4FF(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 8066
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit);
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_StaticInit,(CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		CultureInfo_t9BA817D41AD55AC8BD07480DD8AC22F8FFA378E0* L_0;
		L_0 = CultureInfo_get_CurrentCulture_m8A4580F49DDD7E9DB34C699965423DB8E3BBA9A5(NULL);
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		String_t* L_1;
		L_1 = ((  String_t* (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, String_t*, RuntimeObject*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8)))(__this, _stringLiteral3DCC6243286938BE75C3FA773B9BA71160A2E869, L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 8));
		return L_1;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_m212191DE0383E512D8297CE138DB5C06BF1E6F4A(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 8067
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_8 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_24 = L_8;
	//<source_info:<no-source>:1>
	StringBuilder_t* V_0 = NULL;
	String_t* V_1 = NULL;
	int32_t V_2 = 0;
	{
		StringBuilder_t* L_0 = (StringBuilder_t*)il2cpp_codegen_object_new(StringBuilder_t_il2cpp_TypeInfo_var);
		StringBuilder__ctor_m1D99713357DE05DAFA296633639DB55F8C30587D(L_0, NULL);
		V_0 = L_0;
		RuntimeObject* L_1 = ___1_formatProvider;
		NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* L_2;
		L_2 = NumberFormatInfo_GetInstance_m705987E5E7D3E5EC5C5DD2D088FBC9BCBA0FC31F(L_1, NULL);
		NullCheck(L_2);
		String_t* L_3;
		L_3 = NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline(L_2, NULL);
		V_1 = L_3;
		StringBuilder_t* L_4 = V_0;
		NullCheck(L_4);
		StringBuilder_t* L_5;
		L_5 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_4, ((int32_t)60), NULL);
		V_2 = 0;
		goto IL_0053;
	}

IL_001f:
	{
		StringBuilder_t* L_6 = V_0;
		int32_t L_7 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, L_7, (Il2CppFullySharedGenericStruct*)L_8);
		RuntimeObject* L_9 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), L_8);
		String_t* L_10 = ___0_format;
		RuntimeObject* L_11 = ___1_formatProvider;
		NullCheck(((RuntimeObject*)Castclass((RuntimeObject*)L_9, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var)));
		String_t* L_12;
		L_12 = InterfaceFuncInvoker2< String_t*, String_t*, RuntimeObject* >::Invoke(0, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var, ((RuntimeObject*)Castclass((RuntimeObject*)L_9, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var)), L_10, L_11);
		NullCheck(L_6);
		StringBuilder_t* L_13;
		L_13 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_6, L_12, NULL);
		StringBuilder_t* L_14 = V_0;
		String_t* L_15 = V_1;
		NullCheck(L_14);
		StringBuilder_t* L_16;
		L_16 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_14, L_15, NULL);
		StringBuilder_t* L_17 = V_0;
		NullCheck(L_17);
		StringBuilder_t* L_18;
		L_18 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_17, ((int32_t)32), NULL);
		int32_t L_19 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_0053:
	{
		int32_t L_20 = V_2;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_21;
		L_21 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_20) < ((int32_t)((int32_t)il2cpp_codegen_subtract(L_21, 1)))))
		{
			goto IL_001f;
		}
	}
	{
		StringBuilder_t* L_22 = V_0;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_23;
		L_23 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), __this, ((int32_t)il2cpp_codegen_subtract(L_23, 1)), (Il2CppFullySharedGenericStruct*)L_24);
		RuntimeObject* L_25 = Box(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), L_24);
		String_t* L_26 = ___0_format;
		RuntimeObject* L_27 = ___1_formatProvider;
		NullCheck(((RuntimeObject*)Castclass((RuntimeObject*)L_25, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var)));
		String_t* L_28;
		L_28 = InterfaceFuncInvoker2< String_t*, String_t*, RuntimeObject* >::Invoke(0, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var, ((RuntimeObject*)Castclass((RuntimeObject*)L_25, IFormattable_t235A539BD9771E1E118DB99384BA8385D2F971CA_il2cpp_TypeInfo_var)), L_26, L_27);
		NullCheck(L_22);
		StringBuilder_t* L_29;
		L_29 = StringBuilder_Append_m08904D74E0C78E5F36DCD9C9303BDD07886D9F7D(L_22, L_28, NULL);
		StringBuilder_t* L_30 = V_0;
		NullCheck(L_30);
		StringBuilder_t* L_31;
		L_31 = StringBuilder_Append_m71228B30F05724CD2CD96D9611DCD61BFB96A6E1(L_30, ((int32_t)62), NULL);
		StringBuilder_t* L_32 = V_0;
		NullCheck(L_32);
		String_t* L_33;
		L_33 = VirtualFuncInvoker0< String_t* >::Invoke(3, L_32);
		return L_33;
	}
}
IL2CPP_EXTERN_C  String_t* Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F_AdjustorThunk (RuntimeObject* __this, String_t* ___0_format, RuntimeObject* ___1_formatProvider, const RuntimeMethod* method)
{
	Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* _thisAdjusted;
	_thisAdjusted = il2cpp_codegen_get_raw_data<Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2>(__this);
	String_t* _returnValue;
	_returnValue = Vector_1_ToString_mB21C58D9FD6C9A89DF0D786C50F960E551B1FB8F(_thisAdjusted, ___0_format, ___1_formatProvider, method);
	return _returnValue;
}
// Method Definition Index: 8068
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Equality_mD9D7F968EF2059FD426D9AB1B5252CF82BD4F4EF_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_left, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_0 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_1;
		L_1 = ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5)))((&___0_left), L_0, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_1;
	}
}
// Method Definition Index: 8069
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_op_Inequality_mA9CAF8F4CFD39F3FFFD040F57C0FA7EAD5508999_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_left, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_0 = ___0_left;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_1 = ___1_right;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9)))(L_0, L_1, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 9));
		return (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 8070
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A Vector_1_op_Explicit_mEFC640DAE334AF4ED540F354F6FCDF25F74E95A2_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* L_0 = (Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A*)(&(&___0_value)->___register);
		Vector_1_t566D05A9DE75BCD8F12F1E09AC3F8A4BC01BF92A L_1;
		memset((&L_1), 0, sizeof(L_1));
		Vector_1__ctor_mEA86543744A54FCE590FDBF012FAE9037A5F1606((&L_1), L_0, NULL);
		return L_1;
	}
}
// Method Definition Index: 8071
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 Vector_1_Equals_m96E39C24E7761FC3F454C5A26242AE329FDEFC99_fshared (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___0_left, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_9 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_27 = L_9;
	const Il2CppFullySharedGenericStruct L_46 = L_9;
	const Il2CppFullySharedGenericStruct L_65 = L_9;
	const Il2CppFullySharedGenericStruct L_84 = L_9;
	const Il2CppFullySharedGenericStruct L_103 = L_9;
	const Il2CppFullySharedGenericStruct L_122 = L_9;
	const Il2CppFullySharedGenericStruct L_142 = L_9;
	const Il2CppFullySharedGenericStruct L_162 = L_9;
	const Il2CppFullySharedGenericStruct L_181 = L_9;
	const Il2CppFullySharedGenericStruct L_11 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_29 = L_11;
	const Il2CppFullySharedGenericStruct L_48 = L_11;
	const Il2CppFullySharedGenericStruct L_67 = L_11;
	const Il2CppFullySharedGenericStruct L_86 = L_11;
	const Il2CppFullySharedGenericStruct L_105 = L_11;
	const Il2CppFullySharedGenericStruct L_124 = L_11;
	const Il2CppFullySharedGenericStruct L_144 = L_11;
	const Il2CppFullySharedGenericStruct L_164 = L_11;
	const Il2CppFullySharedGenericStruct L_183 = L_11;
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	int8_t* V_2 = NULL;
	int32_t V_3 = 0;
	uint16_t* V_4 = NULL;
	int32_t V_5 = 0;
	int16_t* V_6 = NULL;
	int32_t V_7 = 0;
	uint32_t* V_8 = NULL;
	int32_t V_9 = 0;
	int32_t* V_10 = NULL;
	int32_t V_11 = 0;
	uint64_t* V_12 = NULL;
	int32_t V_13 = 0;
	int64_t* V_14 = NULL;
	int32_t V_15 = 0;
	float* V_16 = NULL;
	int32_t V_17 = 0;
	double* V_18 = NULL;
	int32_t V_19 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A V_20;
	memset((&V_20), 0, sizeof(V_20));
	uint8_t* G_B5_0 = NULL;
	uint8_t* G_B4_0 = NULL;
	int32_t G_B6_0 = 0;
	uint8_t* G_B6_1 = NULL;
	int8_t* G_B13_0 = NULL;
	int8_t* G_B12_0 = NULL;
	int32_t G_B14_0 = 0;
	int8_t* G_B14_1 = NULL;
	uint16_t* G_B21_0 = NULL;
	uint16_t* G_B20_0 = NULL;
	int32_t G_B22_0 = 0;
	uint16_t* G_B22_1 = NULL;
	int16_t* G_B29_0 = NULL;
	int16_t* G_B28_0 = NULL;
	int32_t G_B30_0 = 0;
	int16_t* G_B30_1 = NULL;
	uint32_t* G_B37_0 = NULL;
	uint32_t* G_B36_0 = NULL;
	uint32_t G_B38_0 = 0;
	uint32_t* G_B38_1 = NULL;
	int32_t* G_B45_0 = NULL;
	int32_t* G_B44_0 = NULL;
	int32_t G_B46_0 = 0;
	int32_t* G_B46_1 = NULL;
	uint64_t* G_B53_0 = NULL;
	uint64_t* G_B52_0 = NULL;
	uint64_t G_B54_0 = 0;
	uint64_t* G_B54_1 = NULL;
	int64_t* G_B61_0 = NULL;
	int64_t* G_B60_0 = NULL;
	int64_t G_B62_0 = 0;
	int64_t* G_B62_1 = NULL;
	float* G_B69_0 = NULL;
	float* G_B68_0 = NULL;
	float G_B70_0 = 0.0f;
	float* G_B70_1 = NULL;
	double* G_B77_0 = NULL;
	double* G_B76_0 = NULL;
	double G_B78_0 = 0.0;
	double* G_B78_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B85_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B84_0 = NULL;
	int32_t G_B86_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B86_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B88_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B87_0 = NULL;
	int32_t G_B89_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B89_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B91_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B90_0 = NULL;
	int32_t G_B92_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B92_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B94_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B93_0 = NULL;
	int32_t G_B95_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B95_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B97_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B96_0 = NULL;
	int32_t G_B98_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B98_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B100_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B99_0 = NULL;
	int32_t G_B101_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B101_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B103_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B102_0 = NULL;
	int32_t G_B104_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B104_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B106_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B105_0 = NULL;
	int32_t G_B107_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B107_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B109_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B108_0 = NULL;
	int32_t G_B110_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B110_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B112_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B111_0 = NULL;
	int32_t G_B113_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B113_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B115_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B114_0 = NULL;
	int32_t G_B116_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B116_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B118_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B117_0 = NULL;
	int32_t G_B119_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B119_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B121_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B120_0 = NULL;
	int32_t G_B122_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B122_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B124_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B123_0 = NULL;
	int32_t G_B125_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B125_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B127_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B126_0 = NULL;
	int32_t G_B128_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B128_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B130_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B129_0 = NULL;
	int32_t G_B131_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B131_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B135_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B134_0 = NULL;
	int32_t G_B136_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B136_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B138_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B137_0 = NULL;
	int32_t G_B139_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B139_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B141_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B140_0 = NULL;
	int32_t G_B142_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B142_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B144_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B143_0 = NULL;
	int32_t G_B145_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B145_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B147_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B146_0 = NULL;
	int32_t G_B148_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B148_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B150_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B149_0 = NULL;
	int32_t G_B151_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B151_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B153_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B152_0 = NULL;
	int32_t G_B154_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B154_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B156_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B155_0 = NULL;
	int32_t G_B157_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B157_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B159_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B158_0 = NULL;
	int32_t G_B160_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B160_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B162_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B161_0 = NULL;
	int32_t G_B163_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B163_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B165_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B164_0 = NULL;
	int32_t G_B166_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B166_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B168_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B167_0 = NULL;
	int32_t G_B169_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B169_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B171_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B170_0 = NULL;
	int32_t G_B172_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B172_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B174_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B173_0 = NULL;
	int32_t G_B175_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B175_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B177_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B176_0 = NULL;
	int32_t G_B178_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B178_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B180_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B179_0 = NULL;
	int32_t G_B181_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B181_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B185_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B184_0 = NULL;
	int32_t G_B186_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B186_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B188_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B187_0 = NULL;
	int32_t G_B189_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B189_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B191_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B190_0 = NULL;
	int32_t G_B192_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B192_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B194_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B193_0 = NULL;
	int32_t G_B195_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B195_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B197_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B196_0 = NULL;
	int32_t G_B198_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B198_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B200_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B199_0 = NULL;
	int32_t G_B201_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B201_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B203_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B202_0 = NULL;
	int32_t G_B204_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B204_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B206_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B205_0 = NULL;
	int32_t G_B207_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B207_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B211_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B210_0 = NULL;
	int32_t G_B212_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B212_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B214_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B213_0 = NULL;
	int32_t G_B215_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B215_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B217_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B216_0 = NULL;
	int32_t G_B218_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B218_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B220_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B219_0 = NULL;
	int32_t G_B221_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B221_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B223_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B222_0 = NULL;
	int32_t G_B224_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B224_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B226_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B225_0 = NULL;
	int32_t G_B227_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B227_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B229_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B228_0 = NULL;
	int32_t G_B230_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B230_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B232_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B231_0 = NULL;
	int32_t G_B233_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B233_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B237_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B236_0 = NULL;
	uint32_t G_B238_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B238_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B240_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B239_0 = NULL;
	uint32_t G_B241_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B241_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B243_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B242_0 = NULL;
	uint32_t G_B244_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B244_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B246_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B245_0 = NULL;
	uint32_t G_B247_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B247_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B251_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B250_0 = NULL;
	int32_t G_B252_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B252_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B254_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B253_0 = NULL;
	int32_t G_B255_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B255_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B257_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B256_0 = NULL;
	int32_t G_B258_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B258_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B260_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B259_0 = NULL;
	int32_t G_B261_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B261_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B265_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B264_0 = NULL;
	uint64_t G_B266_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B266_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B268_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B267_0 = NULL;
	uint64_t G_B269_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B269_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B273_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B272_0 = NULL;
	int64_t G_B274_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B274_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B276_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B275_0 = NULL;
	int64_t G_B277_0 = 0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B277_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B281_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B280_0 = NULL;
	float G_B282_0 = 0.0f;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B282_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B284_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B283_0 = NULL;
	float G_B285_0 = 0.0f;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B285_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B287_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B286_0 = NULL;
	float G_B288_0 = 0.0f;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B288_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B290_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B289_0 = NULL;
	float G_B291_0 = 0.0f;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B291_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B295_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B294_0 = NULL;
	double G_B296_0 = 0.0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B296_1 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B298_0 = NULL;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B297_0 = NULL;
	double G_B299_0 = 0.0;
	Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A* G_B299_1 = NULL;
	{
		bool L_0;
		L_0 = Vector_get_IsHardwareAccelerated_m783509258751EBED64CBD9F387EC1BB4A15088AA(NULL);
		if (!L_0)
		{
			goto IL_0447;
		}
	}
	{
		bool L_1 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_1)
		{
			goto IL_0068;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_2;
		L_2 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_3 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_2,NULL));
		uintptr_t L_4 = L_3;
		int8_t* L_5;
		if (L_4 == 0)
		{
			L_5 = NULL;
		}
		else
		{
			L_5 = (int8_t*)alloca(L_4);
			memset(L_5, 0, L_4);
		}
		V_0 = (uint8_t*)L_5;
		V_1 = 0;
		goto IL_0059;
	}

IL_0032:
	{
		uint8_t* L_6 = V_0;
		int32_t L_7 = V_1;
		int32_t L_8 = V_1;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_8, (Il2CppFullySharedGenericStruct*)L_9);
		int32_t L_10 = V_1;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_10, (Il2CppFullySharedGenericStruct*)L_11);
		bool L_12;
		L_12 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_9, L_11);
		if (L_12)
		{
			G_B5_0 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_6, L_7));
			goto IL_004f;
		}
		G_B4_0 = ((uint8_t*)il2cpp_codegen_add((intptr_t)L_6, L_7));
	}
	{
		G_B6_0 = 0;
		G_B6_1 = G_B4_0;
		goto IL_0054;
	}

IL_004f:
	{
		uint8_t L_13;
		L_13 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B6_0 = ((int32_t)(L_13));
		G_B6_1 = G_B5_0;
	}

IL_0054:
	{
		*(((int8_t*)G_B6_1)) = ((int8_t)G_B6_0);
		int32_t L_14 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, 1));
	}

IL_0059:
	{
		int32_t L_15 = V_1;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_16;
		L_16 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_15) < ((int32_t)L_16)))
		{
			goto IL_0032;
		}
	}
	{
		uint8_t* L_17 = V_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_18;
		memset((&L_18), 0, sizeof(L_18));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_18), (void*)L_17, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_18;
	}

IL_0068:
	{
		bool L_19 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_19)
		{
			goto IL_00c6;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_20;
		L_20 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_21 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_20,NULL));
		uintptr_t L_22 = L_21;
		int8_t* L_23;
		if (L_22 == 0)
		{
			L_23 = NULL;
		}
		else
		{
			L_23 = (int8_t*)alloca(L_22);
			memset(L_23, 0, L_22);
		}
		V_2 = L_23;
		V_3 = 0;
		goto IL_00b7;
	}

IL_0090:
	{
		int8_t* L_24 = V_2;
		int32_t L_25 = V_3;
		int32_t L_26 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_26, (Il2CppFullySharedGenericStruct*)L_27);
		int32_t L_28 = V_3;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_28, (Il2CppFullySharedGenericStruct*)L_29);
		bool L_30;
		L_30 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_27, L_29);
		if (L_30)
		{
			G_B13_0 = ((int8_t*)il2cpp_codegen_add((intptr_t)L_24, L_25));
			goto IL_00ad;
		}
		G_B12_0 = ((int8_t*)il2cpp_codegen_add((intptr_t)L_24, L_25));
	}
	{
		G_B14_0 = 0;
		G_B14_1 = G_B12_0;
		goto IL_00b2;
	}

IL_00ad:
	{
		int8_t L_31;
		L_31 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B14_0 = ((int32_t)(L_31));
		G_B14_1 = G_B13_0;
	}

IL_00b2:
	{
		*(G_B14_1) = ((int8_t)G_B14_0);
		int32_t L_32 = V_3;
		V_3 = ((int32_t)il2cpp_codegen_add(L_32, 1));
	}

IL_00b7:
	{
		int32_t L_33 = V_3;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_34;
		L_34 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_33) < ((int32_t)L_34)))
		{
			goto IL_0090;
		}
	}
	{
		int8_t* L_35 = V_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_36;
		memset((&L_36), 0, sizeof(L_36));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_36), (void*)L_35, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_36;
	}

IL_00c6:
	{
		bool L_37 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_37)
		{
			goto IL_0133;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_38;
		L_38 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_39 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_38,NULL));
		if ((uintptr_t)L_39 * (uintptr_t)2 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_40 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_39, 2));
		int8_t* L_41;
		if (L_40 == 0)
		{
			L_41 = NULL;
		}
		else
		{
			L_41 = (int8_t*)alloca(L_40);
			memset(L_41, 0, L_40);
		}
		V_4 = (uint16_t*)L_41;
		V_5 = 0;
		goto IL_0122;
	}

IL_00f2:
	{
		uint16_t* L_42 = V_4;
		int32_t L_43 = V_5;
		intptr_t L_44 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_43,NULL));
		int32_t L_45 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_45, (Il2CppFullySharedGenericStruct*)L_46);
		int32_t L_47 = V_5;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_47, (Il2CppFullySharedGenericStruct*)L_48);
		bool L_49;
		L_49 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_46, L_48);
		if (L_49)
		{
			G_B21_0 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_42, ((intptr_t)il2cpp_codegen_multiply(L_44, 2))));
			goto IL_0116;
		}
		G_B20_0 = ((uint16_t*)il2cpp_codegen_add((intptr_t)L_42, ((intptr_t)il2cpp_codegen_multiply(L_44, 2))));
	}
	{
		G_B22_0 = 0;
		G_B22_1 = G_B20_0;
		goto IL_011b;
	}

IL_0116:
	{
		uint16_t L_50;
		L_50 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B22_0 = ((int32_t)(L_50));
		G_B22_1 = G_B21_0;
	}

IL_011b:
	{
		*(((int16_t*)G_B22_1)) = ((int16_t)G_B22_0);
		int32_t L_51 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_51, 1));
	}

IL_0122:
	{
		int32_t L_52 = V_5;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_53;
		L_53 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_52) < ((int32_t)L_53)))
		{
			goto IL_00f2;
		}
	}
	{
		uint16_t* L_54 = V_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_55;
		memset((&L_55), 0, sizeof(L_55));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_55), (void*)L_54, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_55;
	}

IL_0133:
	{
		bool L_56 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_56)
		{
			goto IL_01a0;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_57;
		L_57 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_58 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_57,NULL));
		if ((uintptr_t)L_58 * (uintptr_t)2 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_59 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_58, 2));
		int8_t* L_60;
		if (L_59 == 0)
		{
			L_60 = NULL;
		}
		else
		{
			L_60 = (int8_t*)alloca(L_59);
			memset(L_60, 0, L_59);
		}
		V_6 = (int16_t*)L_60;
		V_7 = 0;
		goto IL_018f;
	}

IL_015f:
	{
		int16_t* L_61 = V_6;
		int32_t L_62 = V_7;
		intptr_t L_63 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_62,NULL));
		int32_t L_64 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_64, (Il2CppFullySharedGenericStruct*)L_65);
		int32_t L_66 = V_7;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_66, (Il2CppFullySharedGenericStruct*)L_67);
		bool L_68;
		L_68 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_65, L_67);
		if (L_68)
		{
			G_B29_0 = ((int16_t*)il2cpp_codegen_add((intptr_t)L_61, ((intptr_t)il2cpp_codegen_multiply(L_63, 2))));
			goto IL_0183;
		}
		G_B28_0 = ((int16_t*)il2cpp_codegen_add((intptr_t)L_61, ((intptr_t)il2cpp_codegen_multiply(L_63, 2))));
	}
	{
		G_B30_0 = 0;
		G_B30_1 = G_B28_0;
		goto IL_0188;
	}

IL_0183:
	{
		int16_t L_69;
		L_69 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B30_0 = ((int32_t)(L_69));
		G_B30_1 = G_B29_0;
	}

IL_0188:
	{
		*(G_B30_1) = ((int16_t)G_B30_0);
		int32_t L_70 = V_7;
		V_7 = ((int32_t)il2cpp_codegen_add(L_70, 1));
	}

IL_018f:
	{
		int32_t L_71 = V_7;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_72;
		L_72 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_71) < ((int32_t)L_72)))
		{
			goto IL_015f;
		}
	}
	{
		int16_t* L_73 = V_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_74;
		memset((&L_74), 0, sizeof(L_74));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_74), (void*)L_73, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_74;
	}

IL_01a0:
	{
		bool L_75 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_75)
		{
			goto IL_020d;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_76;
		L_76 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_77 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_76,NULL));
		if ((uintptr_t)L_77 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_78 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_77, 4));
		int8_t* L_79;
		if (L_78 == 0)
		{
			L_79 = NULL;
		}
		else
		{
			L_79 = (int8_t*)alloca(L_78);
			memset(L_79, 0, L_78);
		}
		V_8 = (uint32_t*)L_79;
		V_9 = 0;
		goto IL_01fc;
	}

IL_01cc:
	{
		uint32_t* L_80 = V_8;
		int32_t L_81 = V_9;
		intptr_t L_82 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_81,NULL));
		int32_t L_83 = V_9;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_83, (Il2CppFullySharedGenericStruct*)L_84);
		int32_t L_85 = V_9;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_85, (Il2CppFullySharedGenericStruct*)L_86);
		bool L_87;
		L_87 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_84, L_86);
		if (L_87)
		{
			G_B37_0 = ((uint32_t*)il2cpp_codegen_add((intptr_t)L_80, ((intptr_t)il2cpp_codegen_multiply(L_82, 4))));
			goto IL_01f0;
		}
		G_B36_0 = ((uint32_t*)il2cpp_codegen_add((intptr_t)L_80, ((intptr_t)il2cpp_codegen_multiply(L_82, 4))));
	}
	{
		G_B38_0 = ((uint32_t)(0));
		G_B38_1 = G_B36_0;
		goto IL_01f5;
	}

IL_01f0:
	{
		uint32_t L_88;
		L_88 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B38_0 = L_88;
		G_B38_1 = G_B37_0;
	}

IL_01f5:
	{
		*(((int32_t*)G_B38_1)) = ((int32_t)G_B38_0);
		int32_t L_89 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_89, 1));
	}

IL_01fc:
	{
		int32_t L_90 = V_9;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_91;
		L_91 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_90) < ((int32_t)L_91)))
		{
			goto IL_01cc;
		}
	}
	{
		uint32_t* L_92 = V_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_93;
		memset((&L_93), 0, sizeof(L_93));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_93), (void*)L_92, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_93;
	}

IL_020d:
	{
		bool L_94 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_94)
		{
			goto IL_027a;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_95;
		L_95 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_96 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_95,NULL));
		if ((uintptr_t)L_96 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_97 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_96, 4));
		int8_t* L_98;
		if (L_97 == 0)
		{
			L_98 = NULL;
		}
		else
		{
			L_98 = (int8_t*)alloca(L_97);
			memset(L_98, 0, L_97);
		}
		V_10 = (int32_t*)L_98;
		V_11 = 0;
		goto IL_0269;
	}

IL_0239:
	{
		int32_t* L_99 = V_10;
		int32_t L_100 = V_11;
		intptr_t L_101 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_100,NULL));
		int32_t L_102 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_102, (Il2CppFullySharedGenericStruct*)L_103);
		int32_t L_104 = V_11;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_104, (Il2CppFullySharedGenericStruct*)L_105);
		bool L_106;
		L_106 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_103, L_105);
		if (L_106)
		{
			G_B45_0 = ((int32_t*)il2cpp_codegen_add((intptr_t)L_99, ((intptr_t)il2cpp_codegen_multiply(L_101, 4))));
			goto IL_025d;
		}
		G_B44_0 = ((int32_t*)il2cpp_codegen_add((intptr_t)L_99, ((intptr_t)il2cpp_codegen_multiply(L_101, 4))));
	}
	{
		G_B46_0 = 0;
		G_B46_1 = G_B44_0;
		goto IL_0262;
	}

IL_025d:
	{
		int32_t L_107;
		L_107 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B46_0 = L_107;
		G_B46_1 = G_B45_0;
	}

IL_0262:
	{
		*(G_B46_1) = G_B46_0;
		int32_t L_108 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_108, 1));
	}

IL_0269:
	{
		int32_t L_109 = V_11;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_110;
		L_110 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_109) < ((int32_t)L_110)))
		{
			goto IL_0239;
		}
	}
	{
		int32_t* L_111 = V_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_112;
		memset((&L_112), 0, sizeof(L_112));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_112), (void*)L_111, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_112;
	}

IL_027a:
	{
		bool L_113 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_113)
		{
			goto IL_02e8;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_114;
		L_114 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_115 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_114,NULL));
		if ((uintptr_t)L_115 * (uintptr_t)8 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_116 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_115, 8));
		int8_t* L_117;
		if (L_116 == 0)
		{
			L_117 = NULL;
		}
		else
		{
			L_117 = (int8_t*)alloca(L_116);
			memset(L_117, 0, L_116);
		}
		V_12 = (uint64_t*)L_117;
		V_13 = 0;
		goto IL_02d7;
	}

IL_02a6:
	{
		uint64_t* L_118 = V_12;
		int32_t L_119 = V_13;
		intptr_t L_120 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_119,NULL));
		int32_t L_121 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_121, (Il2CppFullySharedGenericStruct*)L_122);
		int32_t L_123 = V_13;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_123, (Il2CppFullySharedGenericStruct*)L_124);
		bool L_125;
		L_125 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_122, L_124);
		if (L_125)
		{
			G_B53_0 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_118, ((intptr_t)il2cpp_codegen_multiply(L_120, 8))));
			goto IL_02cb;
		}
		G_B52_0 = ((uint64_t*)il2cpp_codegen_add((intptr_t)L_118, ((intptr_t)il2cpp_codegen_multiply(L_120, 8))));
	}
	{
		int64_t L_126 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B54_0 = ((uint64_t)(L_126));
		G_B54_1 = G_B52_0;
		goto IL_02d0;
	}

IL_02cb:
	{
		uint64_t L_127;
		L_127 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B54_0 = L_127;
		G_B54_1 = G_B53_0;
	}

IL_02d0:
	{
		*(((int64_t*)G_B54_1)) = ((int64_t)G_B54_0);
		int32_t L_128 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_128, 1));
	}

IL_02d7:
	{
		int32_t L_129 = V_13;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_130;
		L_130 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_129) < ((int32_t)L_130)))
		{
			goto IL_02a6;
		}
	}
	{
		uint64_t* L_131 = V_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_132;
		memset((&L_132), 0, sizeof(L_132));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_132), (void*)L_131, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_132;
	}

IL_02e8:
	{
		bool L_133 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_133)
		{
			goto IL_0356;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_134;
		L_134 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_135 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_134,NULL));
		if ((uintptr_t)L_135 * (uintptr_t)8 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_136 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_135, 8));
		int8_t* L_137;
		if (L_136 == 0)
		{
			L_137 = NULL;
		}
		else
		{
			L_137 = (int8_t*)alloca(L_136);
			memset(L_137, 0, L_136);
		}
		V_14 = (int64_t*)L_137;
		V_15 = 0;
		goto IL_0345;
	}

IL_0314:
	{
		int64_t* L_138 = V_14;
		int32_t L_139 = V_15;
		intptr_t L_140 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_139,NULL));
		int32_t L_141 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_141, (Il2CppFullySharedGenericStruct*)L_142);
		int32_t L_143 = V_15;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_143, (Il2CppFullySharedGenericStruct*)L_144);
		bool L_145;
		L_145 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_142, L_144);
		if (L_145)
		{
			G_B61_0 = ((int64_t*)il2cpp_codegen_add((intptr_t)L_138, ((intptr_t)il2cpp_codegen_multiply(L_140, 8))));
			goto IL_0339;
		}
		G_B60_0 = ((int64_t*)il2cpp_codegen_add((intptr_t)L_138, ((intptr_t)il2cpp_codegen_multiply(L_140, 8))));
	}
	{
		int64_t L_146 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B62_0 = L_146;
		G_B62_1 = G_B60_0;
		goto IL_033e;
	}

IL_0339:
	{
		int64_t L_147;
		L_147 = ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline(NULL);
		G_B62_0 = L_147;
		G_B62_1 = G_B61_0;
	}

IL_033e:
	{
		*(G_B62_1) = G_B62_0;
		int32_t L_148 = V_15;
		V_15 = ((int32_t)il2cpp_codegen_add(L_148, 1));
	}

IL_0345:
	{
		int32_t L_149 = V_15;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_150;
		L_150 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_149) < ((int32_t)L_150)))
		{
			goto IL_0314;
		}
	}
	{
		int64_t* L_151 = V_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_152;
		memset((&L_152), 0, sizeof(L_152));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_152), (void*)L_151, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_152;
	}

IL_0356:
	{
		bool L_153 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_153)
		{
			goto IL_03c7;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_154;
		L_154 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_155 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_154,NULL));
		if ((uintptr_t)L_155 * (uintptr_t)4 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_156 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_155, 4));
		int8_t* L_157;
		if (L_156 == 0)
		{
			L_157 = NULL;
		}
		else
		{
			L_157 = (int8_t*)alloca(L_156);
			memset(L_157, 0, L_156);
		}
		V_16 = (float*)L_157;
		V_17 = 0;
		goto IL_03b6;
	}

IL_0382:
	{
		float* L_158 = V_16;
		int32_t L_159 = V_17;
		intptr_t L_160 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_159,NULL));
		int32_t L_161 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_161, (Il2CppFullySharedGenericStruct*)L_162);
		int32_t L_163 = V_17;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_163, (Il2CppFullySharedGenericStruct*)L_164);
		bool L_165;
		L_165 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_162, L_164);
		if (L_165)
		{
			G_B69_0 = ((float*)il2cpp_codegen_add((intptr_t)L_158, ((intptr_t)il2cpp_codegen_multiply(L_160, 4))));
			goto IL_03aa;
		}
		G_B68_0 = ((float*)il2cpp_codegen_add((intptr_t)L_158, ((intptr_t)il2cpp_codegen_multiply(L_160, 4))));
	}
	{
		G_B70_0 = (0.0f);
		G_B70_1 = G_B68_0;
		goto IL_03af;
	}

IL_03aa:
	{
		float L_166;
		L_166 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B70_0 = L_166;
		G_B70_1 = G_B69_0;
	}

IL_03af:
	{
		*(G_B70_1) = G_B70_0;
		int32_t L_167 = V_17;
		V_17 = ((int32_t)il2cpp_codegen_add(L_167, 1));
	}

IL_03b6:
	{
		int32_t L_168 = V_17;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_169;
		L_169 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_168) < ((int32_t)L_169)))
		{
			goto IL_0382;
		}
	}
	{
		float* L_170 = V_16;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_171;
		memset((&L_171), 0, sizeof(L_171));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_171), (void*)L_170, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_171;
	}

IL_03c7:
	{
		bool L_172 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_172)
		{
			goto IL_043c;
		}
	}
	{
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_173;
		L_173 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		uintptr_t L_174 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(L_173,NULL));
		if ((uintptr_t)L_174 * (uintptr_t)8 > (uintptr_t)kIl2CppUIntPtrMax)
			IL2CPP_RAISE_MANAGED_EXCEPTION(il2cpp_codegen_get_overflow_exception(), method);
		intptr_t L_175 = ((intptr_t)il2cpp_codegen_multiply((intptr_t)L_174, 8));
		int8_t* L_176;
		if (L_175 == 0)
		{
			L_176 = NULL;
		}
		else
		{
			L_176 = (int8_t*)alloca(L_175);
			memset(L_176, 0, L_175);
		}
		V_18 = (double*)L_176;
		V_19 = 0;
		goto IL_042b;
	}

IL_03f3:
	{
		double* L_177 = V_18;
		int32_t L_178 = V_19;
		intptr_t L_179 = (il2cpp_codegen_conv<intptr_t,int32_t,int32_t,false,false>(L_178,NULL));
		int32_t L_180 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___0_left), L_180, (Il2CppFullySharedGenericStruct*)L_181);
		int32_t L_182 = V_19;
		InvokerActionInvoker2< int32_t, Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 6), (&___1_right), L_182, (Il2CppFullySharedGenericStruct*)L_183);
		bool L_184;
		L_184 = InvokerFuncInvoker2< bool, Il2CppFullySharedGenericStruct, Il2CppFullySharedGenericStruct >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 7), NULL, L_181, L_183);
		if (L_184)
		{
			G_B77_0 = ((double*)il2cpp_codegen_add((intptr_t)L_177, ((intptr_t)il2cpp_codegen_multiply(L_179, 8))));
			goto IL_041f;
		}
		G_B76_0 = ((double*)il2cpp_codegen_add((intptr_t)L_177, ((intptr_t)il2cpp_codegen_multiply(L_179, 8))));
	}
	{
		G_B78_0 = (0.0);
		G_B78_1 = G_B76_0;
		goto IL_0424;
	}

IL_041f:
	{
		double L_185;
		L_185 = ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline(NULL);
		G_B78_0 = L_185;
		G_B78_1 = G_B77_0;
	}

IL_0424:
	{
		*(G_B78_1) = G_B78_0;
		int32_t L_186 = V_19;
		V_19 = ((int32_t)il2cpp_codegen_add(L_186, 1));
	}

IL_042b:
	{
		int32_t L_187 = V_19;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_188;
		L_188 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 3));
		if ((((int32_t)L_187) < ((int32_t)L_188)))
		{
			goto IL_03f3;
		}
	}
	{
		double* L_189 = V_18;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_190;
		memset((&L_190), 0, sizeof(L_190));
		Vector_1__ctor_mD3ECCFAE19D970AAEFCC15057E4B90EEA62EB001((&L_190), (void*)L_189, il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 10));
		return L_190;
	}

IL_043c:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_191 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_191, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_191, method);
	}

IL_0447:
	{
		il2cpp_codegen_initobj((&V_20), sizeof(Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A));
		bool L_192 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_192)
		{
			goto IL_06e5;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_193 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_194 = L_193.___register;
		uint8_t L_195 = L_194.___byte_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_196 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_197 = L_196.___register;
		uint8_t L_198 = L_197.___byte_0;
		if ((((int32_t)L_195) == ((int32_t)L_198)))
		{
			G_B85_0 = (&V_20);
			goto IL_048a;
		}
		G_B84_0 = (&V_20);
	}
	{
		G_B86_0 = 0;
		G_B86_1 = G_B84_0;
		goto IL_048f;
	}

IL_048a:
	{
		uint8_t L_199;
		L_199 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B86_0 = ((int32_t)(L_199));
		G_B86_1 = G_B85_0;
	}

IL_048f:
	{
		G_B86_1->___byte_0 = (uint8_t)G_B86_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_200 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_201 = L_200.___register;
		uint8_t L_202 = L_201.___byte_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_203 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_204 = L_203.___register;
		uint8_t L_205 = L_204.___byte_1;
		if ((((int32_t)L_202) == ((int32_t)L_205)))
		{
			G_B88_0 = (&V_20);
			goto IL_04b1;
		}
		G_B87_0 = (&V_20);
	}
	{
		G_B89_0 = 0;
		G_B89_1 = G_B87_0;
		goto IL_04b6;
	}

IL_04b1:
	{
		uint8_t L_206;
		L_206 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B89_0 = ((int32_t)(L_206));
		G_B89_1 = G_B88_0;
	}

IL_04b6:
	{
		G_B89_1->___byte_1 = (uint8_t)G_B89_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_207 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_208 = L_207.___register;
		uint8_t L_209 = L_208.___byte_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_210 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_211 = L_210.___register;
		uint8_t L_212 = L_211.___byte_2;
		if ((((int32_t)L_209) == ((int32_t)L_212)))
		{
			G_B91_0 = (&V_20);
			goto IL_04d8;
		}
		G_B90_0 = (&V_20);
	}
	{
		G_B92_0 = 0;
		G_B92_1 = G_B90_0;
		goto IL_04dd;
	}

IL_04d8:
	{
		uint8_t L_213;
		L_213 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B92_0 = ((int32_t)(L_213));
		G_B92_1 = G_B91_0;
	}

IL_04dd:
	{
		G_B92_1->___byte_2 = (uint8_t)G_B92_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_214 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_215 = L_214.___register;
		uint8_t L_216 = L_215.___byte_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_217 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_218 = L_217.___register;
		uint8_t L_219 = L_218.___byte_3;
		if ((((int32_t)L_216) == ((int32_t)L_219)))
		{
			G_B94_0 = (&V_20);
			goto IL_04ff;
		}
		G_B93_0 = (&V_20);
	}
	{
		G_B95_0 = 0;
		G_B95_1 = G_B93_0;
		goto IL_0504;
	}

IL_04ff:
	{
		uint8_t L_220;
		L_220 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B95_0 = ((int32_t)(L_220));
		G_B95_1 = G_B94_0;
	}

IL_0504:
	{
		G_B95_1->___byte_3 = (uint8_t)G_B95_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_221 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_222 = L_221.___register;
		uint8_t L_223 = L_222.___byte_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_224 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_225 = L_224.___register;
		uint8_t L_226 = L_225.___byte_4;
		if ((((int32_t)L_223) == ((int32_t)L_226)))
		{
			G_B97_0 = (&V_20);
			goto IL_0526;
		}
		G_B96_0 = (&V_20);
	}
	{
		G_B98_0 = 0;
		G_B98_1 = G_B96_0;
		goto IL_052b;
	}

IL_0526:
	{
		uint8_t L_227;
		L_227 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B98_0 = ((int32_t)(L_227));
		G_B98_1 = G_B97_0;
	}

IL_052b:
	{
		G_B98_1->___byte_4 = (uint8_t)G_B98_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_228 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_229 = L_228.___register;
		uint8_t L_230 = L_229.___byte_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_231 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_232 = L_231.___register;
		uint8_t L_233 = L_232.___byte_5;
		if ((((int32_t)L_230) == ((int32_t)L_233)))
		{
			G_B100_0 = (&V_20);
			goto IL_054d;
		}
		G_B99_0 = (&V_20);
	}
	{
		G_B101_0 = 0;
		G_B101_1 = G_B99_0;
		goto IL_0552;
	}

IL_054d:
	{
		uint8_t L_234;
		L_234 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B101_0 = ((int32_t)(L_234));
		G_B101_1 = G_B100_0;
	}

IL_0552:
	{
		G_B101_1->___byte_5 = (uint8_t)G_B101_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_235 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_236 = L_235.___register;
		uint8_t L_237 = L_236.___byte_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_238 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_239 = L_238.___register;
		uint8_t L_240 = L_239.___byte_6;
		if ((((int32_t)L_237) == ((int32_t)L_240)))
		{
			G_B103_0 = (&V_20);
			goto IL_0574;
		}
		G_B102_0 = (&V_20);
	}
	{
		G_B104_0 = 0;
		G_B104_1 = G_B102_0;
		goto IL_0579;
	}

IL_0574:
	{
		uint8_t L_241;
		L_241 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B104_0 = ((int32_t)(L_241));
		G_B104_1 = G_B103_0;
	}

IL_0579:
	{
		G_B104_1->___byte_6 = (uint8_t)G_B104_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_242 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_243 = L_242.___register;
		uint8_t L_244 = L_243.___byte_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_245 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_246 = L_245.___register;
		uint8_t L_247 = L_246.___byte_7;
		if ((((int32_t)L_244) == ((int32_t)L_247)))
		{
			G_B106_0 = (&V_20);
			goto IL_059b;
		}
		G_B105_0 = (&V_20);
	}
	{
		G_B107_0 = 0;
		G_B107_1 = G_B105_0;
		goto IL_05a0;
	}

IL_059b:
	{
		uint8_t L_248;
		L_248 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B107_0 = ((int32_t)(L_248));
		G_B107_1 = G_B106_0;
	}

IL_05a0:
	{
		G_B107_1->___byte_7 = (uint8_t)G_B107_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_249 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_250 = L_249.___register;
		uint8_t L_251 = L_250.___byte_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_252 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_253 = L_252.___register;
		uint8_t L_254 = L_253.___byte_8;
		if ((((int32_t)L_251) == ((int32_t)L_254)))
		{
			G_B109_0 = (&V_20);
			goto IL_05c2;
		}
		G_B108_0 = (&V_20);
	}
	{
		G_B110_0 = 0;
		G_B110_1 = G_B108_0;
		goto IL_05c7;
	}

IL_05c2:
	{
		uint8_t L_255;
		L_255 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B110_0 = ((int32_t)(L_255));
		G_B110_1 = G_B109_0;
	}

IL_05c7:
	{
		G_B110_1->___byte_8 = (uint8_t)G_B110_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_256 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_257 = L_256.___register;
		uint8_t L_258 = L_257.___byte_9;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_259 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_260 = L_259.___register;
		uint8_t L_261 = L_260.___byte_9;
		if ((((int32_t)L_258) == ((int32_t)L_261)))
		{
			G_B112_0 = (&V_20);
			goto IL_05e9;
		}
		G_B111_0 = (&V_20);
	}
	{
		G_B113_0 = 0;
		G_B113_1 = G_B111_0;
		goto IL_05ee;
	}

IL_05e9:
	{
		uint8_t L_262;
		L_262 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B113_0 = ((int32_t)(L_262));
		G_B113_1 = G_B112_0;
	}

IL_05ee:
	{
		G_B113_1->___byte_9 = (uint8_t)G_B113_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_263 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_264 = L_263.___register;
		uint8_t L_265 = L_264.___byte_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_266 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_267 = L_266.___register;
		uint8_t L_268 = L_267.___byte_10;
		if ((((int32_t)L_265) == ((int32_t)L_268)))
		{
			G_B115_0 = (&V_20);
			goto IL_0610;
		}
		G_B114_0 = (&V_20);
	}
	{
		G_B116_0 = 0;
		G_B116_1 = G_B114_0;
		goto IL_0615;
	}

IL_0610:
	{
		uint8_t L_269;
		L_269 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B116_0 = ((int32_t)(L_269));
		G_B116_1 = G_B115_0;
	}

IL_0615:
	{
		G_B116_1->___byte_10 = (uint8_t)G_B116_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_270 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_271 = L_270.___register;
		uint8_t L_272 = L_271.___byte_11;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_273 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_274 = L_273.___register;
		uint8_t L_275 = L_274.___byte_11;
		if ((((int32_t)L_272) == ((int32_t)L_275)))
		{
			G_B118_0 = (&V_20);
			goto IL_0637;
		}
		G_B117_0 = (&V_20);
	}
	{
		G_B119_0 = 0;
		G_B119_1 = G_B117_0;
		goto IL_063c;
	}

IL_0637:
	{
		uint8_t L_276;
		L_276 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B119_0 = ((int32_t)(L_276));
		G_B119_1 = G_B118_0;
	}

IL_063c:
	{
		G_B119_1->___byte_11 = (uint8_t)G_B119_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_277 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_278 = L_277.___register;
		uint8_t L_279 = L_278.___byte_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_280 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_281 = L_280.___register;
		uint8_t L_282 = L_281.___byte_12;
		if ((((int32_t)L_279) == ((int32_t)L_282)))
		{
			G_B121_0 = (&V_20);
			goto IL_065e;
		}
		G_B120_0 = (&V_20);
	}
	{
		G_B122_0 = 0;
		G_B122_1 = G_B120_0;
		goto IL_0663;
	}

IL_065e:
	{
		uint8_t L_283;
		L_283 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B122_0 = ((int32_t)(L_283));
		G_B122_1 = G_B121_0;
	}

IL_0663:
	{
		G_B122_1->___byte_12 = (uint8_t)G_B122_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_284 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_285 = L_284.___register;
		uint8_t L_286 = L_285.___byte_13;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_287 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_288 = L_287.___register;
		uint8_t L_289 = L_288.___byte_13;
		if ((((int32_t)L_286) == ((int32_t)L_289)))
		{
			G_B124_0 = (&V_20);
			goto IL_0685;
		}
		G_B123_0 = (&V_20);
	}
	{
		G_B125_0 = 0;
		G_B125_1 = G_B123_0;
		goto IL_068a;
	}

IL_0685:
	{
		uint8_t L_290;
		L_290 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B125_0 = ((int32_t)(L_290));
		G_B125_1 = G_B124_0;
	}

IL_068a:
	{
		G_B125_1->___byte_13 = (uint8_t)G_B125_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_291 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_292 = L_291.___register;
		uint8_t L_293 = L_292.___byte_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_294 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_295 = L_294.___register;
		uint8_t L_296 = L_295.___byte_14;
		if ((((int32_t)L_293) == ((int32_t)L_296)))
		{
			G_B127_0 = (&V_20);
			goto IL_06ac;
		}
		G_B126_0 = (&V_20);
	}
	{
		G_B128_0 = 0;
		G_B128_1 = G_B126_0;
		goto IL_06b1;
	}

IL_06ac:
	{
		uint8_t L_297;
		L_297 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B128_0 = ((int32_t)(L_297));
		G_B128_1 = G_B127_0;
	}

IL_06b1:
	{
		G_B128_1->___byte_14 = (uint8_t)G_B128_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_298 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_299 = L_298.___register;
		uint8_t L_300 = L_299.___byte_15;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_301 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_302 = L_301.___register;
		uint8_t L_303 = L_302.___byte_15;
		if ((((int32_t)L_300) == ((int32_t)L_303)))
		{
			G_B130_0 = (&V_20);
			goto IL_06d3;
		}
		G_B129_0 = (&V_20);
	}
	{
		G_B131_0 = 0;
		G_B131_1 = G_B129_0;
		goto IL_06d8;
	}

IL_06d3:
	{
		uint8_t L_304;
		L_304 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		G_B131_0 = ((int32_t)(L_304));
		G_B131_1 = G_B130_0;
	}

IL_06d8:
	{
		G_B131_1->___byte_15 = (uint8_t)G_B131_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_305;
		memset((&L_305), 0, sizeof(L_305));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_305), (&V_20), NULL);
		return L_305;
	}

IL_06e5:
	{
		bool L_306 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_306)
		{
			goto IL_097b;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_307 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_308 = L_307.___register;
		int8_t L_309 = L_308.___sbyte_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_310 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_311 = L_310.___register;
		int8_t L_312 = L_311.___sbyte_0;
		if ((((int32_t)L_309) == ((int32_t)L_312)))
		{
			G_B135_0 = (&V_20);
			goto IL_0720;
		}
		G_B134_0 = (&V_20);
	}
	{
		G_B136_0 = 0;
		G_B136_1 = G_B134_0;
		goto IL_0725;
	}

IL_0720:
	{
		int8_t L_313;
		L_313 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B136_0 = ((int32_t)(L_313));
		G_B136_1 = G_B135_0;
	}

IL_0725:
	{
		G_B136_1->___sbyte_0 = (int8_t)G_B136_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_314 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_315 = L_314.___register;
		int8_t L_316 = L_315.___sbyte_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_317 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_318 = L_317.___register;
		int8_t L_319 = L_318.___sbyte_1;
		if ((((int32_t)L_316) == ((int32_t)L_319)))
		{
			G_B138_0 = (&V_20);
			goto IL_0747;
		}
		G_B137_0 = (&V_20);
	}
	{
		G_B139_0 = 0;
		G_B139_1 = G_B137_0;
		goto IL_074c;
	}

IL_0747:
	{
		int8_t L_320;
		L_320 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B139_0 = ((int32_t)(L_320));
		G_B139_1 = G_B138_0;
	}

IL_074c:
	{
		G_B139_1->___sbyte_1 = (int8_t)G_B139_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_321 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_322 = L_321.___register;
		int8_t L_323 = L_322.___sbyte_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_324 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_325 = L_324.___register;
		int8_t L_326 = L_325.___sbyte_2;
		if ((((int32_t)L_323) == ((int32_t)L_326)))
		{
			G_B141_0 = (&V_20);
			goto IL_076e;
		}
		G_B140_0 = (&V_20);
	}
	{
		G_B142_0 = 0;
		G_B142_1 = G_B140_0;
		goto IL_0773;
	}

IL_076e:
	{
		int8_t L_327;
		L_327 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B142_0 = ((int32_t)(L_327));
		G_B142_1 = G_B141_0;
	}

IL_0773:
	{
		G_B142_1->___sbyte_2 = (int8_t)G_B142_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_328 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_329 = L_328.___register;
		int8_t L_330 = L_329.___sbyte_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_331 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_332 = L_331.___register;
		int8_t L_333 = L_332.___sbyte_3;
		if ((((int32_t)L_330) == ((int32_t)L_333)))
		{
			G_B144_0 = (&V_20);
			goto IL_0795;
		}
		G_B143_0 = (&V_20);
	}
	{
		G_B145_0 = 0;
		G_B145_1 = G_B143_0;
		goto IL_079a;
	}

IL_0795:
	{
		int8_t L_334;
		L_334 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B145_0 = ((int32_t)(L_334));
		G_B145_1 = G_B144_0;
	}

IL_079a:
	{
		G_B145_1->___sbyte_3 = (int8_t)G_B145_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_335 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_336 = L_335.___register;
		int8_t L_337 = L_336.___sbyte_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_338 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_339 = L_338.___register;
		int8_t L_340 = L_339.___sbyte_4;
		if ((((int32_t)L_337) == ((int32_t)L_340)))
		{
			G_B147_0 = (&V_20);
			goto IL_07bc;
		}
		G_B146_0 = (&V_20);
	}
	{
		G_B148_0 = 0;
		G_B148_1 = G_B146_0;
		goto IL_07c1;
	}

IL_07bc:
	{
		int8_t L_341;
		L_341 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B148_0 = ((int32_t)(L_341));
		G_B148_1 = G_B147_0;
	}

IL_07c1:
	{
		G_B148_1->___sbyte_4 = (int8_t)G_B148_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_342 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_343 = L_342.___register;
		int8_t L_344 = L_343.___sbyte_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_345 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_346 = L_345.___register;
		int8_t L_347 = L_346.___sbyte_5;
		if ((((int32_t)L_344) == ((int32_t)L_347)))
		{
			G_B150_0 = (&V_20);
			goto IL_07e3;
		}
		G_B149_0 = (&V_20);
	}
	{
		G_B151_0 = 0;
		G_B151_1 = G_B149_0;
		goto IL_07e8;
	}

IL_07e3:
	{
		int8_t L_348;
		L_348 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B151_0 = ((int32_t)(L_348));
		G_B151_1 = G_B150_0;
	}

IL_07e8:
	{
		G_B151_1->___sbyte_5 = (int8_t)G_B151_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_349 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_350 = L_349.___register;
		int8_t L_351 = L_350.___sbyte_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_352 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_353 = L_352.___register;
		int8_t L_354 = L_353.___sbyte_6;
		if ((((int32_t)L_351) == ((int32_t)L_354)))
		{
			G_B153_0 = (&V_20);
			goto IL_080a;
		}
		G_B152_0 = (&V_20);
	}
	{
		G_B154_0 = 0;
		G_B154_1 = G_B152_0;
		goto IL_080f;
	}

IL_080a:
	{
		int8_t L_355;
		L_355 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B154_0 = ((int32_t)(L_355));
		G_B154_1 = G_B153_0;
	}

IL_080f:
	{
		G_B154_1->___sbyte_6 = (int8_t)G_B154_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_356 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_357 = L_356.___register;
		int8_t L_358 = L_357.___sbyte_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_359 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_360 = L_359.___register;
		int8_t L_361 = L_360.___sbyte_7;
		if ((((int32_t)L_358) == ((int32_t)L_361)))
		{
			G_B156_0 = (&V_20);
			goto IL_0831;
		}
		G_B155_0 = (&V_20);
	}
	{
		G_B157_0 = 0;
		G_B157_1 = G_B155_0;
		goto IL_0836;
	}

IL_0831:
	{
		int8_t L_362;
		L_362 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B157_0 = ((int32_t)(L_362));
		G_B157_1 = G_B156_0;
	}

IL_0836:
	{
		G_B157_1->___sbyte_7 = (int8_t)G_B157_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_363 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_364 = L_363.___register;
		int8_t L_365 = L_364.___sbyte_8;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_366 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_367 = L_366.___register;
		int8_t L_368 = L_367.___sbyte_8;
		if ((((int32_t)L_365) == ((int32_t)L_368)))
		{
			G_B159_0 = (&V_20);
			goto IL_0858;
		}
		G_B158_0 = (&V_20);
	}
	{
		G_B160_0 = 0;
		G_B160_1 = G_B158_0;
		goto IL_085d;
	}

IL_0858:
	{
		int8_t L_369;
		L_369 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B160_0 = ((int32_t)(L_369));
		G_B160_1 = G_B159_0;
	}

IL_085d:
	{
		G_B160_1->___sbyte_8 = (int8_t)G_B160_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_370 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_371 = L_370.___register;
		int8_t L_372 = L_371.___sbyte_9;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_373 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_374 = L_373.___register;
		int8_t L_375 = L_374.___sbyte_9;
		if ((((int32_t)L_372) == ((int32_t)L_375)))
		{
			G_B162_0 = (&V_20);
			goto IL_087f;
		}
		G_B161_0 = (&V_20);
	}
	{
		G_B163_0 = 0;
		G_B163_1 = G_B161_0;
		goto IL_0884;
	}

IL_087f:
	{
		int8_t L_376;
		L_376 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B163_0 = ((int32_t)(L_376));
		G_B163_1 = G_B162_0;
	}

IL_0884:
	{
		G_B163_1->___sbyte_9 = (int8_t)G_B163_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_377 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_378 = L_377.___register;
		int8_t L_379 = L_378.___sbyte_10;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_380 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_381 = L_380.___register;
		int8_t L_382 = L_381.___sbyte_10;
		if ((((int32_t)L_379) == ((int32_t)L_382)))
		{
			G_B165_0 = (&V_20);
			goto IL_08a6;
		}
		G_B164_0 = (&V_20);
	}
	{
		G_B166_0 = 0;
		G_B166_1 = G_B164_0;
		goto IL_08ab;
	}

IL_08a6:
	{
		int8_t L_383;
		L_383 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B166_0 = ((int32_t)(L_383));
		G_B166_1 = G_B165_0;
	}

IL_08ab:
	{
		G_B166_1->___sbyte_10 = (int8_t)G_B166_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_384 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_385 = L_384.___register;
		int8_t L_386 = L_385.___sbyte_11;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_387 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_388 = L_387.___register;
		int8_t L_389 = L_388.___sbyte_11;
		if ((((int32_t)L_386) == ((int32_t)L_389)))
		{
			G_B168_0 = (&V_20);
			goto IL_08cd;
		}
		G_B167_0 = (&V_20);
	}
	{
		G_B169_0 = 0;
		G_B169_1 = G_B167_0;
		goto IL_08d2;
	}

IL_08cd:
	{
		int8_t L_390;
		L_390 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B169_0 = ((int32_t)(L_390));
		G_B169_1 = G_B168_0;
	}

IL_08d2:
	{
		G_B169_1->___sbyte_11 = (int8_t)G_B169_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_391 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_392 = L_391.___register;
		int8_t L_393 = L_392.___sbyte_12;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_394 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_395 = L_394.___register;
		int8_t L_396 = L_395.___sbyte_12;
		if ((((int32_t)L_393) == ((int32_t)L_396)))
		{
			G_B171_0 = (&V_20);
			goto IL_08f4;
		}
		G_B170_0 = (&V_20);
	}
	{
		G_B172_0 = 0;
		G_B172_1 = G_B170_0;
		goto IL_08f9;
	}

IL_08f4:
	{
		int8_t L_397;
		L_397 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B172_0 = ((int32_t)(L_397));
		G_B172_1 = G_B171_0;
	}

IL_08f9:
	{
		G_B172_1->___sbyte_12 = (int8_t)G_B172_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_398 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_399 = L_398.___register;
		int8_t L_400 = L_399.___sbyte_13;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_401 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_402 = L_401.___register;
		int8_t L_403 = L_402.___sbyte_13;
		if ((((int32_t)L_400) == ((int32_t)L_403)))
		{
			G_B174_0 = (&V_20);
			goto IL_091b;
		}
		G_B173_0 = (&V_20);
	}
	{
		G_B175_0 = 0;
		G_B175_1 = G_B173_0;
		goto IL_0920;
	}

IL_091b:
	{
		int8_t L_404;
		L_404 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B175_0 = ((int32_t)(L_404));
		G_B175_1 = G_B174_0;
	}

IL_0920:
	{
		G_B175_1->___sbyte_13 = (int8_t)G_B175_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_405 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_406 = L_405.___register;
		int8_t L_407 = L_406.___sbyte_14;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_408 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_409 = L_408.___register;
		int8_t L_410 = L_409.___sbyte_14;
		if ((((int32_t)L_407) == ((int32_t)L_410)))
		{
			G_B177_0 = (&V_20);
			goto IL_0942;
		}
		G_B176_0 = (&V_20);
	}
	{
		G_B178_0 = 0;
		G_B178_1 = G_B176_0;
		goto IL_0947;
	}

IL_0942:
	{
		int8_t L_411;
		L_411 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B178_0 = ((int32_t)(L_411));
		G_B178_1 = G_B177_0;
	}

IL_0947:
	{
		G_B178_1->___sbyte_14 = (int8_t)G_B178_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_412 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_413 = L_412.___register;
		int8_t L_414 = L_413.___sbyte_15;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_415 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_416 = L_415.___register;
		int8_t L_417 = L_416.___sbyte_15;
		if ((((int32_t)L_414) == ((int32_t)L_417)))
		{
			G_B180_0 = (&V_20);
			goto IL_0969;
		}
		G_B179_0 = (&V_20);
	}
	{
		G_B181_0 = 0;
		G_B181_1 = G_B179_0;
		goto IL_096e;
	}

IL_0969:
	{
		int8_t L_418;
		L_418 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		G_B181_0 = ((int32_t)(L_418));
		G_B181_1 = G_B180_0;
	}

IL_096e:
	{
		G_B181_1->___sbyte_15 = (int8_t)G_B181_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_419;
		memset((&L_419), 0, sizeof(L_419));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_419), (&V_20), NULL);
		return L_419;
	}

IL_097b:
	{
		bool L_420 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_420)
		{
			goto IL_0ad9;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_421 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_422 = L_421.___register;
		uint16_t L_423 = L_422.___uint16_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_424 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_425 = L_424.___register;
		uint16_t L_426 = L_425.___uint16_0;
		if ((((int32_t)L_423) == ((int32_t)L_426)))
		{
			G_B185_0 = (&V_20);
			goto IL_09b6;
		}
		G_B184_0 = (&V_20);
	}
	{
		G_B186_0 = 0;
		G_B186_1 = G_B184_0;
		goto IL_09bb;
	}

IL_09b6:
	{
		uint16_t L_427;
		L_427 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B186_0 = ((int32_t)(L_427));
		G_B186_1 = G_B185_0;
	}

IL_09bb:
	{
		G_B186_1->___uint16_0 = (uint16_t)G_B186_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_428 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_429 = L_428.___register;
		uint16_t L_430 = L_429.___uint16_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_431 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_432 = L_431.___register;
		uint16_t L_433 = L_432.___uint16_1;
		if ((((int32_t)L_430) == ((int32_t)L_433)))
		{
			G_B188_0 = (&V_20);
			goto IL_09dd;
		}
		G_B187_0 = (&V_20);
	}
	{
		G_B189_0 = 0;
		G_B189_1 = G_B187_0;
		goto IL_09e2;
	}

IL_09dd:
	{
		uint16_t L_434;
		L_434 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B189_0 = ((int32_t)(L_434));
		G_B189_1 = G_B188_0;
	}

IL_09e2:
	{
		G_B189_1->___uint16_1 = (uint16_t)G_B189_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_435 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_436 = L_435.___register;
		uint16_t L_437 = L_436.___uint16_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_438 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_439 = L_438.___register;
		uint16_t L_440 = L_439.___uint16_2;
		if ((((int32_t)L_437) == ((int32_t)L_440)))
		{
			G_B191_0 = (&V_20);
			goto IL_0a04;
		}
		G_B190_0 = (&V_20);
	}
	{
		G_B192_0 = 0;
		G_B192_1 = G_B190_0;
		goto IL_0a09;
	}

IL_0a04:
	{
		uint16_t L_441;
		L_441 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B192_0 = ((int32_t)(L_441));
		G_B192_1 = G_B191_0;
	}

IL_0a09:
	{
		G_B192_1->___uint16_2 = (uint16_t)G_B192_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_442 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_443 = L_442.___register;
		uint16_t L_444 = L_443.___uint16_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_445 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_446 = L_445.___register;
		uint16_t L_447 = L_446.___uint16_3;
		if ((((int32_t)L_444) == ((int32_t)L_447)))
		{
			G_B194_0 = (&V_20);
			goto IL_0a2b;
		}
		G_B193_0 = (&V_20);
	}
	{
		G_B195_0 = 0;
		G_B195_1 = G_B193_0;
		goto IL_0a30;
	}

IL_0a2b:
	{
		uint16_t L_448;
		L_448 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B195_0 = ((int32_t)(L_448));
		G_B195_1 = G_B194_0;
	}

IL_0a30:
	{
		G_B195_1->___uint16_3 = (uint16_t)G_B195_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_449 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_450 = L_449.___register;
		uint16_t L_451 = L_450.___uint16_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_452 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_453 = L_452.___register;
		uint16_t L_454 = L_453.___uint16_4;
		if ((((int32_t)L_451) == ((int32_t)L_454)))
		{
			G_B197_0 = (&V_20);
			goto IL_0a52;
		}
		G_B196_0 = (&V_20);
	}
	{
		G_B198_0 = 0;
		G_B198_1 = G_B196_0;
		goto IL_0a57;
	}

IL_0a52:
	{
		uint16_t L_455;
		L_455 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B198_0 = ((int32_t)(L_455));
		G_B198_1 = G_B197_0;
	}

IL_0a57:
	{
		G_B198_1->___uint16_4 = (uint16_t)G_B198_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_456 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_457 = L_456.___register;
		uint16_t L_458 = L_457.___uint16_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_459 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_460 = L_459.___register;
		uint16_t L_461 = L_460.___uint16_5;
		if ((((int32_t)L_458) == ((int32_t)L_461)))
		{
			G_B200_0 = (&V_20);
			goto IL_0a79;
		}
		G_B199_0 = (&V_20);
	}
	{
		G_B201_0 = 0;
		G_B201_1 = G_B199_0;
		goto IL_0a7e;
	}

IL_0a79:
	{
		uint16_t L_462;
		L_462 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B201_0 = ((int32_t)(L_462));
		G_B201_1 = G_B200_0;
	}

IL_0a7e:
	{
		G_B201_1->___uint16_5 = (uint16_t)G_B201_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_463 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_464 = L_463.___register;
		uint16_t L_465 = L_464.___uint16_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_466 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_467 = L_466.___register;
		uint16_t L_468 = L_467.___uint16_6;
		if ((((int32_t)L_465) == ((int32_t)L_468)))
		{
			G_B203_0 = (&V_20);
			goto IL_0aa0;
		}
		G_B202_0 = (&V_20);
	}
	{
		G_B204_0 = 0;
		G_B204_1 = G_B202_0;
		goto IL_0aa5;
	}

IL_0aa0:
	{
		uint16_t L_469;
		L_469 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B204_0 = ((int32_t)(L_469));
		G_B204_1 = G_B203_0;
	}

IL_0aa5:
	{
		G_B204_1->___uint16_6 = (uint16_t)G_B204_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_470 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_471 = L_470.___register;
		uint16_t L_472 = L_471.___uint16_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_473 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_474 = L_473.___register;
		uint16_t L_475 = L_474.___uint16_7;
		if ((((int32_t)L_472) == ((int32_t)L_475)))
		{
			G_B206_0 = (&V_20);
			goto IL_0ac7;
		}
		G_B205_0 = (&V_20);
	}
	{
		G_B207_0 = 0;
		G_B207_1 = G_B205_0;
		goto IL_0acc;
	}

IL_0ac7:
	{
		uint16_t L_476;
		L_476 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		G_B207_0 = ((int32_t)(L_476));
		G_B207_1 = G_B206_0;
	}

IL_0acc:
	{
		G_B207_1->___uint16_7 = (uint16_t)G_B207_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_477;
		memset((&L_477), 0, sizeof(L_477));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_477), (&V_20), NULL);
		return L_477;
	}

IL_0ad9:
	{
		bool L_478 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_478)
		{
			goto IL_0c37;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_479 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_480 = L_479.___register;
		int16_t L_481 = L_480.___int16_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_482 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_483 = L_482.___register;
		int16_t L_484 = L_483.___int16_0;
		if ((((int32_t)L_481) == ((int32_t)L_484)))
		{
			G_B211_0 = (&V_20);
			goto IL_0b14;
		}
		G_B210_0 = (&V_20);
	}
	{
		G_B212_0 = 0;
		G_B212_1 = G_B210_0;
		goto IL_0b19;
	}

IL_0b14:
	{
		int16_t L_485;
		L_485 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B212_0 = ((int32_t)(L_485));
		G_B212_1 = G_B211_0;
	}

IL_0b19:
	{
		G_B212_1->___int16_0 = (int16_t)G_B212_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_486 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_487 = L_486.___register;
		int16_t L_488 = L_487.___int16_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_489 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_490 = L_489.___register;
		int16_t L_491 = L_490.___int16_1;
		if ((((int32_t)L_488) == ((int32_t)L_491)))
		{
			G_B214_0 = (&V_20);
			goto IL_0b3b;
		}
		G_B213_0 = (&V_20);
	}
	{
		G_B215_0 = 0;
		G_B215_1 = G_B213_0;
		goto IL_0b40;
	}

IL_0b3b:
	{
		int16_t L_492;
		L_492 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B215_0 = ((int32_t)(L_492));
		G_B215_1 = G_B214_0;
	}

IL_0b40:
	{
		G_B215_1->___int16_1 = (int16_t)G_B215_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_493 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_494 = L_493.___register;
		int16_t L_495 = L_494.___int16_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_496 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_497 = L_496.___register;
		int16_t L_498 = L_497.___int16_2;
		if ((((int32_t)L_495) == ((int32_t)L_498)))
		{
			G_B217_0 = (&V_20);
			goto IL_0b62;
		}
		G_B216_0 = (&V_20);
	}
	{
		G_B218_0 = 0;
		G_B218_1 = G_B216_0;
		goto IL_0b67;
	}

IL_0b62:
	{
		int16_t L_499;
		L_499 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B218_0 = ((int32_t)(L_499));
		G_B218_1 = G_B217_0;
	}

IL_0b67:
	{
		G_B218_1->___int16_2 = (int16_t)G_B218_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_500 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_501 = L_500.___register;
		int16_t L_502 = L_501.___int16_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_503 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_504 = L_503.___register;
		int16_t L_505 = L_504.___int16_3;
		if ((((int32_t)L_502) == ((int32_t)L_505)))
		{
			G_B220_0 = (&V_20);
			goto IL_0b89;
		}
		G_B219_0 = (&V_20);
	}
	{
		G_B221_0 = 0;
		G_B221_1 = G_B219_0;
		goto IL_0b8e;
	}

IL_0b89:
	{
		int16_t L_506;
		L_506 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B221_0 = ((int32_t)(L_506));
		G_B221_1 = G_B220_0;
	}

IL_0b8e:
	{
		G_B221_1->___int16_3 = (int16_t)G_B221_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_507 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_508 = L_507.___register;
		int16_t L_509 = L_508.___int16_4;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_510 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_511 = L_510.___register;
		int16_t L_512 = L_511.___int16_4;
		if ((((int32_t)L_509) == ((int32_t)L_512)))
		{
			G_B223_0 = (&V_20);
			goto IL_0bb0;
		}
		G_B222_0 = (&V_20);
	}
	{
		G_B224_0 = 0;
		G_B224_1 = G_B222_0;
		goto IL_0bb5;
	}

IL_0bb0:
	{
		int16_t L_513;
		L_513 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B224_0 = ((int32_t)(L_513));
		G_B224_1 = G_B223_0;
	}

IL_0bb5:
	{
		G_B224_1->___int16_4 = (int16_t)G_B224_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_514 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_515 = L_514.___register;
		int16_t L_516 = L_515.___int16_5;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_517 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_518 = L_517.___register;
		int16_t L_519 = L_518.___int16_5;
		if ((((int32_t)L_516) == ((int32_t)L_519)))
		{
			G_B226_0 = (&V_20);
			goto IL_0bd7;
		}
		G_B225_0 = (&V_20);
	}
	{
		G_B227_0 = 0;
		G_B227_1 = G_B225_0;
		goto IL_0bdc;
	}

IL_0bd7:
	{
		int16_t L_520;
		L_520 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B227_0 = ((int32_t)(L_520));
		G_B227_1 = G_B226_0;
	}

IL_0bdc:
	{
		G_B227_1->___int16_5 = (int16_t)G_B227_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_521 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_522 = L_521.___register;
		int16_t L_523 = L_522.___int16_6;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_524 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_525 = L_524.___register;
		int16_t L_526 = L_525.___int16_6;
		if ((((int32_t)L_523) == ((int32_t)L_526)))
		{
			G_B229_0 = (&V_20);
			goto IL_0bfe;
		}
		G_B228_0 = (&V_20);
	}
	{
		G_B230_0 = 0;
		G_B230_1 = G_B228_0;
		goto IL_0c03;
	}

IL_0bfe:
	{
		int16_t L_527;
		L_527 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B230_0 = ((int32_t)(L_527));
		G_B230_1 = G_B229_0;
	}

IL_0c03:
	{
		G_B230_1->___int16_6 = (int16_t)G_B230_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_528 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_529 = L_528.___register;
		int16_t L_530 = L_529.___int16_7;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_531 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_532 = L_531.___register;
		int16_t L_533 = L_532.___int16_7;
		if ((((int32_t)L_530) == ((int32_t)L_533)))
		{
			G_B232_0 = (&V_20);
			goto IL_0c25;
		}
		G_B231_0 = (&V_20);
	}
	{
		G_B233_0 = 0;
		G_B233_1 = G_B231_0;
		goto IL_0c2a;
	}

IL_0c25:
	{
		int16_t L_534;
		L_534 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		G_B233_0 = ((int32_t)(L_534));
		G_B233_1 = G_B232_0;
	}

IL_0c2a:
	{
		G_B233_1->___int16_7 = (int16_t)G_B233_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_535;
		memset((&L_535), 0, sizeof(L_535));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_535), (&V_20), NULL);
		return L_535;
	}

IL_0c37:
	{
		bool L_536 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_536)
		{
			goto IL_0cf9;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_537 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_538 = L_537.___register;
		uint32_t L_539 = L_538.___uint32_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_540 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_541 = L_540.___register;
		uint32_t L_542 = L_541.___uint32_0;
		if ((((int32_t)L_539) == ((int32_t)L_542)))
		{
			G_B237_0 = (&V_20);
			goto IL_0c72;
		}
		G_B236_0 = (&V_20);
	}
	{
		G_B238_0 = ((uint32_t)(0));
		G_B238_1 = G_B236_0;
		goto IL_0c77;
	}

IL_0c72:
	{
		uint32_t L_543;
		L_543 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B238_0 = L_543;
		G_B238_1 = G_B237_0;
	}

IL_0c77:
	{
		G_B238_1->___uint32_0 = G_B238_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_544 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_545 = L_544.___register;
		uint32_t L_546 = L_545.___uint32_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_547 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_548 = L_547.___register;
		uint32_t L_549 = L_548.___uint32_1;
		if ((((int32_t)L_546) == ((int32_t)L_549)))
		{
			G_B240_0 = (&V_20);
			goto IL_0c99;
		}
		G_B239_0 = (&V_20);
	}
	{
		G_B241_0 = ((uint32_t)(0));
		G_B241_1 = G_B239_0;
		goto IL_0c9e;
	}

IL_0c99:
	{
		uint32_t L_550;
		L_550 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B241_0 = L_550;
		G_B241_1 = G_B240_0;
	}

IL_0c9e:
	{
		G_B241_1->___uint32_1 = G_B241_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_551 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_552 = L_551.___register;
		uint32_t L_553 = L_552.___uint32_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_554 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_555 = L_554.___register;
		uint32_t L_556 = L_555.___uint32_2;
		if ((((int32_t)L_553) == ((int32_t)L_556)))
		{
			G_B243_0 = (&V_20);
			goto IL_0cc0;
		}
		G_B242_0 = (&V_20);
	}
	{
		G_B244_0 = ((uint32_t)(0));
		G_B244_1 = G_B242_0;
		goto IL_0cc5;
	}

IL_0cc0:
	{
		uint32_t L_557;
		L_557 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B244_0 = L_557;
		G_B244_1 = G_B243_0;
	}

IL_0cc5:
	{
		G_B244_1->___uint32_2 = G_B244_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_558 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_559 = L_558.___register;
		uint32_t L_560 = L_559.___uint32_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_561 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_562 = L_561.___register;
		uint32_t L_563 = L_562.___uint32_3;
		if ((((int32_t)L_560) == ((int32_t)L_563)))
		{
			G_B246_0 = (&V_20);
			goto IL_0ce7;
		}
		G_B245_0 = (&V_20);
	}
	{
		G_B247_0 = ((uint32_t)(0));
		G_B247_1 = G_B245_0;
		goto IL_0cec;
	}

IL_0ce7:
	{
		uint32_t L_564;
		L_564 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		G_B247_0 = L_564;
		G_B247_1 = G_B246_0;
	}

IL_0cec:
	{
		G_B247_1->___uint32_3 = G_B247_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_565;
		memset((&L_565), 0, sizeof(L_565));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_565), (&V_20), NULL);
		return L_565;
	}

IL_0cf9:
	{
		bool L_566 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_566)
		{
			goto IL_0dbb;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_567 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_568 = L_567.___register;
		int32_t L_569 = L_568.___int32_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_570 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_571 = L_570.___register;
		int32_t L_572 = L_571.___int32_0;
		if ((((int32_t)L_569) == ((int32_t)L_572)))
		{
			G_B251_0 = (&V_20);
			goto IL_0d34;
		}
		G_B250_0 = (&V_20);
	}
	{
		G_B252_0 = 0;
		G_B252_1 = G_B250_0;
		goto IL_0d39;
	}

IL_0d34:
	{
		int32_t L_573;
		L_573 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B252_0 = L_573;
		G_B252_1 = G_B251_0;
	}

IL_0d39:
	{
		G_B252_1->___int32_0 = G_B252_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_574 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_575 = L_574.___register;
		int32_t L_576 = L_575.___int32_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_577 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_578 = L_577.___register;
		int32_t L_579 = L_578.___int32_1;
		if ((((int32_t)L_576) == ((int32_t)L_579)))
		{
			G_B254_0 = (&V_20);
			goto IL_0d5b;
		}
		G_B253_0 = (&V_20);
	}
	{
		G_B255_0 = 0;
		G_B255_1 = G_B253_0;
		goto IL_0d60;
	}

IL_0d5b:
	{
		int32_t L_580;
		L_580 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B255_0 = L_580;
		G_B255_1 = G_B254_0;
	}

IL_0d60:
	{
		G_B255_1->___int32_1 = G_B255_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_581 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_582 = L_581.___register;
		int32_t L_583 = L_582.___int32_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_584 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_585 = L_584.___register;
		int32_t L_586 = L_585.___int32_2;
		if ((((int32_t)L_583) == ((int32_t)L_586)))
		{
			G_B257_0 = (&V_20);
			goto IL_0d82;
		}
		G_B256_0 = (&V_20);
	}
	{
		G_B258_0 = 0;
		G_B258_1 = G_B256_0;
		goto IL_0d87;
	}

IL_0d82:
	{
		int32_t L_587;
		L_587 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B258_0 = L_587;
		G_B258_1 = G_B257_0;
	}

IL_0d87:
	{
		G_B258_1->___int32_2 = G_B258_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_588 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_589 = L_588.___register;
		int32_t L_590 = L_589.___int32_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_591 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_592 = L_591.___register;
		int32_t L_593 = L_592.___int32_3;
		if ((((int32_t)L_590) == ((int32_t)L_593)))
		{
			G_B260_0 = (&V_20);
			goto IL_0da9;
		}
		G_B259_0 = (&V_20);
	}
	{
		G_B261_0 = 0;
		G_B261_1 = G_B259_0;
		goto IL_0dae;
	}

IL_0da9:
	{
		int32_t L_594;
		L_594 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		G_B261_0 = L_594;
		G_B261_1 = G_B260_0;
	}

IL_0dae:
	{
		G_B261_1->___int32_3 = G_B261_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_595;
		memset((&L_595), 0, sizeof(L_595));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_595), (&V_20), NULL);
		return L_595;
	}

IL_0dbb:
	{
		bool L_596 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_596)
		{
			goto IL_0e2e;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_597 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_598 = L_597.___register;
		uint64_t L_599 = L_598.___uint64_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_600 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_601 = L_600.___register;
		uint64_t L_602 = L_601.___uint64_0;
		if ((((int64_t)L_599) == ((int64_t)L_602)))
		{
			G_B265_0 = (&V_20);
			goto IL_0df4;
		}
		G_B264_0 = (&V_20);
	}
	{
		int64_t L_603 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B266_0 = ((uint64_t)(L_603));
		G_B266_1 = G_B264_0;
		goto IL_0df9;
	}

IL_0df4:
	{
		uint64_t L_604;
		L_604 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B266_0 = L_604;
		G_B266_1 = G_B265_0;
	}

IL_0df9:
	{
		G_B266_1->___uint64_0 = G_B266_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_605 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_606 = L_605.___register;
		uint64_t L_607 = L_606.___uint64_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_608 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_609 = L_608.___register;
		uint64_t L_610 = L_609.___uint64_1;
		if ((((int64_t)L_607) == ((int64_t)L_610)))
		{
			G_B268_0 = (&V_20);
			goto IL_0e1c;
		}
		G_B267_0 = (&V_20);
	}
	{
		int64_t L_611 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B269_0 = ((uint64_t)(L_611));
		G_B269_1 = G_B267_0;
		goto IL_0e21;
	}

IL_0e1c:
	{
		uint64_t L_612;
		L_612 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		G_B269_0 = L_612;
		G_B269_1 = G_B268_0;
	}

IL_0e21:
	{
		G_B269_1->___uint64_1 = G_B269_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_613;
		memset((&L_613), 0, sizeof(L_613));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_613), (&V_20), NULL);
		return L_613;
	}

IL_0e2e:
	{
		bool L_614 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_614)
		{
			goto IL_0ea1;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_615 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_616 = L_615.___register;
		int64_t L_617 = L_616.___int64_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_618 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_619 = L_618.___register;
		int64_t L_620 = L_619.___int64_0;
		if ((((int64_t)L_617) == ((int64_t)L_620)))
		{
			G_B273_0 = (&V_20);
			goto IL_0e67;
		}
		G_B272_0 = (&V_20);
	}
	{
		int64_t L_621 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B274_0 = L_621;
		G_B274_1 = G_B272_0;
		goto IL_0e6c;
	}

IL_0e67:
	{
		int64_t L_622;
		L_622 = ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline(NULL);
		G_B274_0 = L_622;
		G_B274_1 = G_B273_0;
	}

IL_0e6c:
	{
		G_B274_1->___int64_0 = G_B274_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_623 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_624 = L_623.___register;
		int64_t L_625 = L_624.___int64_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_626 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_627 = L_626.___register;
		int64_t L_628 = L_627.___int64_1;
		if ((((int64_t)L_625) == ((int64_t)L_628)))
		{
			G_B276_0 = (&V_20);
			goto IL_0e8f;
		}
		G_B275_0 = (&V_20);
	}
	{
		int64_t L_629 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		G_B277_0 = L_629;
		G_B277_1 = G_B275_0;
		goto IL_0e94;
	}

IL_0e8f:
	{
		int64_t L_630;
		L_630 = ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline(NULL);
		G_B277_0 = L_630;
		G_B277_1 = G_B276_0;
	}

IL_0e94:
	{
		G_B277_1->___int64_1 = G_B277_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_631;
		memset((&L_631), 0, sizeof(L_631));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_631), (&V_20), NULL);
		return L_631;
	}

IL_0ea1:
	{
		bool L_632 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_632)
		{
			goto IL_0f73;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_633 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_634 = L_633.___register;
		float L_635 = L_634.___single_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_636 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_637 = L_636.___register;
		float L_638 = L_637.___single_0;
		if ((((float)L_635) == ((float)L_638)))
		{
			G_B281_0 = (&V_20);
			goto IL_0ee0;
		}
		G_B280_0 = (&V_20);
	}
	{
		G_B282_0 = (0.0f);
		G_B282_1 = G_B280_0;
		goto IL_0ee5;
	}

IL_0ee0:
	{
		float L_639;
		L_639 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B282_0 = L_639;
		G_B282_1 = G_B281_0;
	}

IL_0ee5:
	{
		G_B282_1->___single_0 = G_B282_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_640 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_641 = L_640.___register;
		float L_642 = L_641.___single_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_643 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_644 = L_643.___register;
		float L_645 = L_644.___single_1;
		if ((((float)L_642) == ((float)L_645)))
		{
			G_B284_0 = (&V_20);
			goto IL_0f0b;
		}
		G_B283_0 = (&V_20);
	}
	{
		G_B285_0 = (0.0f);
		G_B285_1 = G_B283_0;
		goto IL_0f10;
	}

IL_0f0b:
	{
		float L_646;
		L_646 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B285_0 = L_646;
		G_B285_1 = G_B284_0;
	}

IL_0f10:
	{
		G_B285_1->___single_1 = G_B285_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_647 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_648 = L_647.___register;
		float L_649 = L_648.___single_2;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_650 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_651 = L_650.___register;
		float L_652 = L_651.___single_2;
		if ((((float)L_649) == ((float)L_652)))
		{
			G_B287_0 = (&V_20);
			goto IL_0f36;
		}
		G_B286_0 = (&V_20);
	}
	{
		G_B288_0 = (0.0f);
		G_B288_1 = G_B286_0;
		goto IL_0f3b;
	}

IL_0f36:
	{
		float L_653;
		L_653 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B288_0 = L_653;
		G_B288_1 = G_B287_0;
	}

IL_0f3b:
	{
		G_B288_1->___single_2 = G_B288_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_654 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_655 = L_654.___register;
		float L_656 = L_655.___single_3;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_657 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_658 = L_657.___register;
		float L_659 = L_658.___single_3;
		if ((((float)L_656) == ((float)L_659)))
		{
			G_B290_0 = (&V_20);
			goto IL_0f61;
		}
		G_B289_0 = (&V_20);
	}
	{
		G_B291_0 = (0.0f);
		G_B291_1 = G_B289_0;
		goto IL_0f66;
	}

IL_0f61:
	{
		float L_660;
		L_660 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		G_B291_0 = L_660;
		G_B291_1 = G_B290_0;
	}

IL_0f66:
	{
		G_B291_1->___single_3 = G_B291_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_661;
		memset((&L_661), 0, sizeof(L_661));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_661), (&V_20), NULL);
		return L_661;
	}

IL_0f73:
	{
		bool L_662 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_662)
		{
			goto IL_0ff4;
		}
	}
	{
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_663 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_664 = L_663.___register;
		double L_665 = L_664.___double_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_666 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_667 = L_666.___register;
		double L_668 = L_667.___double_0;
		if ((((double)L_665) == ((double)L_668)))
		{
			G_B295_0 = (&V_20);
			goto IL_0fb3;
		}
		G_B294_0 = (&V_20);
	}
	{
		G_B296_0 = (0.0);
		G_B296_1 = G_B294_0;
		goto IL_0fb8;
	}

IL_0fb3:
	{
		double L_669;
		L_669 = ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline(NULL);
		G_B296_0 = L_669;
		G_B296_1 = G_B295_0;
	}

IL_0fb8:
	{
		G_B296_1->___double_0 = G_B296_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_670 = ___0_left;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_671 = L_670.___register;
		double L_672 = L_671.___double_1;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_673 = ___1_right;
		Register_t483055A1DB8634BA3FBF01BB15D4E94E186A2E7A L_674 = L_673.___register;
		double L_675 = L_674.___double_1;
		if ((((double)L_672) == ((double)L_675)))
		{
			G_B298_0 = (&V_20);
			goto IL_0fe2;
		}
		G_B297_0 = (&V_20);
	}
	{
		G_B299_0 = (0.0);
		G_B299_1 = G_B297_0;
		goto IL_0fe7;
	}

IL_0fe2:
	{
		double L_676;
		L_676 = ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline(NULL);
		G_B299_0 = L_676;
		G_B299_1 = G_B298_0;
	}

IL_0fe7:
	{
		G_B299_1->___double_1 = G_B299_0;
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_677;
		memset((&L_677), 0, sizeof(L_677));
		Vector_1__ctor_mF674294C34FEB07FB44E694358BDA181F564B674((&L_677), (&V_20), NULL);
		return L_677;
	}

IL_0ff4:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_678 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_678, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_678, method);
	}
}
// Method Definition Index: 8072
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Vector_1_ScalarEquals_mD34044F5519631ED7AA89E35525ABFFA300D7895_fshared (Il2CppFullySharedGenericStruct ___0_left, Il2CppFullySharedGenericStruct ___1_right, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_1 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_6 = L_1;
	const Il2CppFullySharedGenericStruct L_11 = L_1;
	const Il2CppFullySharedGenericStruct L_16 = L_1;
	const Il2CppFullySharedGenericStruct L_21 = L_1;
	const Il2CppFullySharedGenericStruct L_26 = L_1;
	const Il2CppFullySharedGenericStruct L_31 = L_1;
	const Il2CppFullySharedGenericStruct L_36 = L_1;
	const Il2CppFullySharedGenericStruct L_41 = L_1;
	const Il2CppFullySharedGenericStruct L_46 = L_1;
	const Il2CppFullySharedGenericStruct L_3 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_8 = L_3;
	const Il2CppFullySharedGenericStruct L_13 = L_3;
	const Il2CppFullySharedGenericStruct L_18 = L_3;
	const Il2CppFullySharedGenericStruct L_23 = L_3;
	const Il2CppFullySharedGenericStruct L_28 = L_3;
	const Il2CppFullySharedGenericStruct L_33 = L_3;
	const Il2CppFullySharedGenericStruct L_38 = L_3;
	const Il2CppFullySharedGenericStruct L_43 = L_3;
	const Il2CppFullySharedGenericStruct L_48 = L_3;
	//<source_info:<no-source>:1>
	{
		bool L_0 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_0)
		{
			goto IL_0034;
		}
	}
	{
		il2cpp_codegen_memcpy(L_1, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_2;
		il2cpp_codegen_box_unbox(L_1, (&L_2), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_3, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint8_t L_4;
		il2cpp_codegen_box_unbox(L_3, (&L_4), sizeof(uint8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_2) == ((int32_t)L_4))? 1 : 0);
	}

IL_0034:
	{
		bool L_5 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_5)
		{
			goto IL_0068;
		}
	}
	{
		il2cpp_codegen_memcpy(L_6, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_7;
		il2cpp_codegen_box_unbox(L_6, (&L_7), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_8, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int8_t L_9;
		il2cpp_codegen_box_unbox(L_8, (&L_9), sizeof(int8_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_7) == ((int32_t)L_9))? 1 : 0);
	}

IL_0068:
	{
		bool L_10 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_10)
		{
			goto IL_009c;
		}
	}
	{
		il2cpp_codegen_memcpy(L_11, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_12;
		il2cpp_codegen_box_unbox(L_11, (&L_12), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_13, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint16_t L_14;
		il2cpp_codegen_box_unbox(L_13, (&L_14), sizeof(uint16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_12) == ((int32_t)L_14))? 1 : 0);
	}

IL_009c:
	{
		bool L_15 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_15)
		{
			goto IL_00d0;
		}
	}
	{
		il2cpp_codegen_memcpy(L_16, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_17;
		il2cpp_codegen_box_unbox(L_16, (&L_17), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_18, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int16_t L_19;
		il2cpp_codegen_box_unbox(L_18, (&L_19), sizeof(int16_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_17) == ((int32_t)L_19))? 1 : 0);
	}

IL_00d0:
	{
		bool L_20 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_20)
		{
			goto IL_0104;
		}
	}
	{
		il2cpp_codegen_memcpy(L_21, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_22;
		il2cpp_codegen_box_unbox(L_21, (&L_22), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_23, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint32_t L_24;
		il2cpp_codegen_box_unbox(L_23, (&L_24), sizeof(uint32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_22) == ((int32_t)L_24))? 1 : 0);
	}

IL_0104:
	{
		bool L_25 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_25)
		{
			goto IL_0138;
		}
	}
	{
		il2cpp_codegen_memcpy(L_26, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_27;
		il2cpp_codegen_box_unbox(L_26, (&L_27), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_28, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int32_t L_29;
		il2cpp_codegen_box_unbox(L_28, (&L_29), sizeof(int32_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		return (bool)((((int32_t)L_27) == ((int32_t)L_29))? 1 : 0);
	}

IL_0138:
	{
		bool L_30 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_30)
		{
			goto IL_016c;
		}
	}
	{
		il2cpp_codegen_memcpy(L_31, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_32;
		il2cpp_codegen_box_unbox(L_31, (&L_32), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_33, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		uint64_t L_34;
		il2cpp_codegen_box_unbox(L_33, (&L_34), sizeof(uint64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var);
		return (bool)((((int64_t)L_32) == ((int64_t)L_34))? 1 : 0);
	}

IL_016c:
	{
		bool L_35 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_35)
		{
			goto IL_01a0;
		}
	}
	{
		il2cpp_codegen_memcpy(L_36, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_37;
		il2cpp_codegen_box_unbox(L_36, (&L_37), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_38, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		int64_t L_39;
		il2cpp_codegen_box_unbox(L_38, (&L_39), sizeof(int64_t), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var);
		return (bool)((((int64_t)L_37) == ((int64_t)L_39))? 1 : 0);
	}

IL_01a0:
	{
		bool L_40 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_40)
		{
			goto IL_01d4;
		}
	}
	{
		il2cpp_codegen_memcpy(L_41, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_42;
		il2cpp_codegen_box_unbox(L_41, (&L_42), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_43, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		float L_44;
		il2cpp_codegen_box_unbox(L_43, (&L_44), sizeof(float), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var);
		return (bool)((((float)L_42) == ((float)L_44))? 1 : 0);
	}

IL_01d4:
	{
		bool L_45 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_45)
		{
			goto IL_0208;
		}
	}
	{
		il2cpp_codegen_memcpy(L_46, ___0_left, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_47;
		il2cpp_codegen_box_unbox(L_46, (&L_47), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		il2cpp_codegen_memcpy(L_48, ___1_right, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		double L_49;
		il2cpp_codegen_box_unbox(L_48, (&L_49), sizeof(double), il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2), Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var);
		return (bool)((((double)L_47) == ((double)L_49))? 1 : 0);
	}

IL_0208:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_50 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_50, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_50, method);
	}
}
// Method Definition Index: 8073
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1_GetOneValue_mE737616FA904E2C6558D22FEA78098714972060A_fshared (Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_2 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_5 = L_2;
	const Il2CppFullySharedGenericStruct L_8 = L_2;
	const Il2CppFullySharedGenericStruct L_11 = L_2;
	const Il2CppFullySharedGenericStruct L_14 = L_2;
	const Il2CppFullySharedGenericStruct L_17 = L_2;
	const Il2CppFullySharedGenericStruct L_21 = L_2;
	const Il2CppFullySharedGenericStruct L_25 = L_2;
	const Il2CppFullySharedGenericStruct L_28 = L_2;
	const Il2CppFullySharedGenericStruct L_31 = L_2;
	//<source_info:<no-source>:1>
	{
		bool L_0 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_0)
		{
			goto IL_0027;
		}
	}
	{
		uint8_t L_1 = 1;
		il2cpp_codegen_box_unbox((&L_1), L_2, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_2, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0027:
	{
		bool L_3 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_3)
		{
			goto IL_004e;
		}
	}
	{
		int8_t L_4 = 1;
		il2cpp_codegen_box_unbox((&L_4), L_5, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_5, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_004e:
	{
		bool L_6 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_6)
		{
			goto IL_0075;
		}
	}
	{
		uint16_t L_7 = 1;
		il2cpp_codegen_box_unbox((&L_7), L_8, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_8, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0075:
	{
		bool L_9 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_9)
		{
			goto IL_009c;
		}
	}
	{
		int16_t L_10 = 1;
		il2cpp_codegen_box_unbox((&L_10), L_11, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_11, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_009c:
	{
		bool L_12 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_12)
		{
			goto IL_00c3;
		}
	}
	{
		uint32_t L_13 = 1;
		il2cpp_codegen_box_unbox((&L_13), L_14, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_14, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00c3:
	{
		bool L_15 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_15)
		{
			goto IL_00ea;
		}
	}
	{
		int32_t L_16 = 1;
		il2cpp_codegen_box_unbox((&L_16), L_17, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_17, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00ea:
	{
		bool L_18 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_18)
		{
			goto IL_0112;
		}
	}
	{
		int64_t L_19 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		uint64_t L_20 = L_19;
		il2cpp_codegen_box_unbox((&L_20), L_21, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_21, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0112:
	{
		bool L_22 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_22)
		{
			goto IL_013a;
		}
	}
	{
		int64_t L_23 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		int64_t L_24 = L_23;
		il2cpp_codegen_box_unbox((&L_24), L_25, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_25, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_013a:
	{
		bool L_26 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_26)
		{
			goto IL_0165;
		}
	}
	{
		float L_27 = (1.0f);
		il2cpp_codegen_box_unbox((&L_27), L_28, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_28, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0165:
	{
		bool L_29 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_29)
		{
			goto IL_0194;
		}
	}
	{
		double L_30 = (1.0);
		il2cpp_codegen_box_unbox((&L_30), L_31, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_31, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0194:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_32 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_32, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_32, method);
	}
}
// Method Definition Index: 8074
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1_GetAllBitsSetValue_mB4736B3DE9ED10228E2F1991D497A98C9FE3E67B_fshared (Il2CppFullySharedGenericStruct* il2cppRetVal, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_3 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_7 = L_3;
	const Il2CppFullySharedGenericStruct L_11 = L_3;
	const Il2CppFullySharedGenericStruct L_15 = L_3;
	const Il2CppFullySharedGenericStruct L_19 = L_3;
	const Il2CppFullySharedGenericStruct L_23 = L_3;
	const Il2CppFullySharedGenericStruct L_27 = L_3;
	const Il2CppFullySharedGenericStruct L_31 = L_3;
	const Il2CppFullySharedGenericStruct L_35 = L_3;
	const Il2CppFullySharedGenericStruct L_39 = L_3;
	//<source_info:<no-source>:1>
	{
		bool L_0 = (Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_0)
		{
			goto IL_002b;
		}
	}
	{
		uint8_t L_1;
		L_1 = ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline(NULL);
		uint8_t L_2 = L_1;
		il2cpp_codegen_box_unbox((&L_2), L_3, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_3, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_002b:
	{
		bool L_4 = (SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_4)
		{
			goto IL_0056;
		}
	}
	{
		int8_t L_5;
		L_5 = ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline(NULL);
		int8_t L_6 = L_5;
		il2cpp_codegen_box_unbox((&L_6), L_7, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_7, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0056:
	{
		bool L_8 = (UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_8)
		{
			goto IL_0081;
		}
	}
	{
		uint16_t L_9;
		L_9 = ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline(NULL);
		uint16_t L_10 = L_9;
		il2cpp_codegen_box_unbox((&L_10), L_11, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_11, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0081:
	{
		bool L_12 = (Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_12)
		{
			goto IL_00ac;
		}
	}
	{
		int16_t L_13;
		L_13 = ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline(NULL);
		int16_t L_14 = L_13;
		il2cpp_codegen_box_unbox((&L_14), L_15, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_15, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00ac:
	{
		bool L_16 = (UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_16)
		{
			goto IL_00d7;
		}
	}
	{
		uint32_t L_17;
		L_17 = ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline(NULL);
		uint32_t L_18 = L_17;
		il2cpp_codegen_box_unbox((&L_18), L_19, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_19, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_00d7:
	{
		bool L_20 = (Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_20)
		{
			goto IL_0102;
		}
	}
	{
		int32_t L_21;
		L_21 = ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline(NULL);
		int32_t L_22 = L_21;
		il2cpp_codegen_box_unbox((&L_22), L_23, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_23, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0102:
	{
		bool L_24 = (UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_24)
		{
			goto IL_012d;
		}
	}
	{
		uint64_t L_25;
		L_25 = ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline(NULL);
		uint64_t L_26 = L_25;
		il2cpp_codegen_box_unbox((&L_26), L_27, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_27, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_012d:
	{
		bool L_28 = (Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_28)
		{
			goto IL_0158;
		}
	}
	{
		int64_t L_29;
		L_29 = ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline(NULL);
		int64_t L_30 = L_29;
		il2cpp_codegen_box_unbox((&L_30), L_31, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_31, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0158:
	{
		bool L_32 = (Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_32)
		{
			goto IL_0183;
		}
	}
	{
		float L_33;
		L_33 = ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline(NULL);
		float L_34 = L_33;
		il2cpp_codegen_box_unbox((&L_34), L_35, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_35, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_0183:
	{
		bool L_36 = (Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var) == (il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		if (!L_36)
		{
			goto IL_01ae;
		}
	}
	{
		double L_37;
		L_37 = ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline(NULL);
		double L_38 = L_37;
		il2cpp_codegen_box_unbox((&L_38), L_39, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE, Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_il2cpp_TypeInfo_var, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
		il2cpp_codegen_memcpy(il2cppRetVal, L_39, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
		return;
	}

IL_01ae:
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_40 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_40, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE310274B02A605A3985345944A620D7D2E019A1A)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_40, method);
	}
}
// Method Definition Index: 8075
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Vector_1__cctor_m5C2E6DBA5BAABD495E2C5E516B928C78DB2A7615_fshared (const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	const uint32_t SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE = il2cpp_codegen_sizeof(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 2));
	const Il2CppFullySharedGenericStruct L_1 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_2 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_4 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	const Il2CppFullySharedGenericStruct L_5 = alloca(SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE);
	//<source_info:<no-source>:1>
	{
		int32_t L_0;
		L_0 = ((  int32_t (*) (const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 12)))(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 12));
		((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_count = L_0;
		il2cpp_codegen_initobj((&((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_zero), sizeof(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2));
		InvokerActionInvoker1< Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 13), NULL, (Il2CppFullySharedGenericStruct*)L_1);
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_3;
		memset((&L_3), 0, sizeof(L_3));
		Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2((&L_3), il2cpp_codegen_memcpy(L_2, L_1, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_one = L_3;
		InvokerActionInvoker1< Il2CppFullySharedGenericStruct* >::Invoke(il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 15)), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 15), NULL, (Il2CppFullySharedGenericStruct*)L_4);
		Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2 L_6;
		memset((&L_6), 0, sizeof(L_6));
		Vector_1__ctor_m7540979061ABB2A0A6D57213359B3E83A1B7B4D2((&L_6), il2cpp_codegen_memcpy(L_5, L_4, SizeOf_T_t7D67093BB2FFD728051D825E6ED6B46C110A9BAE), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 14));
		((Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))->___s_allOnes = L_6;
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 58106
// Method Definition Index: 58107
// Method Definition Index: 58108
// Method Definition Index: 58109
// Method Definition Index: 58110
// Method Definition Index: 58111
// Method Definition Index: 58112
// Method Definition Index: 58113
// Method Definition Index: 58114
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t824317F4B958F7512E8F7300511752937A6C6043* VertexBufferGenerator_1_CreateVertexBuffer_m38BC21F44074E6620C6242EBCA583BA1D4F99395 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_StaticInit);
	//<source_info:<no-source>:1>
	U3CCreateVertexBufferU3Ed__20_tFDD5AE67C5D83FE33DF820C3C9ED617BF88FF2BF V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CHECKED_LOCAL_INIT(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_StaticInit,(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA L_0;
		L_0 = AsyncTaskMethodBuilder_1_Create_mA86694527610A40A01A943B16F0ECDDD8F00982D(NULL);
		(&V_0)->___U3CU3Et__builder = L_0;
		Il2CppCodeGenWriteBarrier((void**)&((&(((&(&V_0)->___U3CU3Et__builder))->___m_coreState))->___m_stateMachine), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&(&V_0)->___U3CU3Et__builder))->___m_coreState))->___m_defaultContextAction), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&(&V_0)->___U3CU3Et__builder))->___m_task), (void*)NULL);
		#endif
		(&V_0)->___U3CU3E4__this = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___U3CU3E4__this), (void*)__this);
		(&V_0)->___U3CU3E1__state = (-1);
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* L_1 = (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA*)(&(&V_0)->___U3CU3Et__builder);
		AsyncTaskMethodBuilder_1_Start_TisU3CCreateVertexBufferU3Ed__20_tFDD5AE67C5D83FE33DF820C3C9ED617BF88FF2BF_mCD2D27028557929EA4186A5F6B77E94149D125D5(L_1, (&V_0), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* L_2 = (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA*)(&(&V_0)->___U3CU3Et__builder);
		Task_1_t824317F4B958F7512E8F7300511752937A6C6043* L_3;
		L_3 = AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943(L_2, AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943_RuntimeMethod_var);
		return L_3;
	}
}
// Method Definition Index: 58115
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGenerator_1_CreateVertexBufferHandle_mAB18126B0DC4DF099A8589F9B082B53184F44F56 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	CHECKED_LOCAL(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_2 = NULL;
	int32_t V_3 = 0;
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_10 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_11;
	memset((&V_11), 0, sizeof(V_11));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* G_B21_0 = NULL;
	VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* G_B20_0 = NULL;
	int32_t G_B22_0 = 0;
	VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* G_B22_1 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B28_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B26_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B27_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B30_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B29_0 = NULL;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 G_B56_0;
	memset((&G_B56_0), 0, sizeof(G_B56_0));
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 L_1;
		memset((&L_1), 0, sizeof(L_1));
		NativeArray_1__ctor_mBA83AAC5DEEF6A424E816BC22A562F9F16331060((&L_1), L_0, 4, 1, NULL);
		__this->___m_Data = L_1;
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 L_2 = __this->___m_Data;
		void* L_3;
		L_3 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_m330509F7AC793C43640F0649AC22729C08D9A935_inline(L_2, NULL);
		V_0 = (uint8_t*)L_3;
		V_1 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_4);
		int32_t L_5 = 0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_6 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		V_2 = L_6;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_7 = V_2;
		NullCheck(L_7);
		int32_t L_8;
		L_8 = Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7(L_7, NULL);
		V_3 = L_8;
		int32_t L_9 = V_3;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0148;
		}
	}
	{
		int32_t L_10 = V_3;
		if ((((int32_t)L_10) <= ((int32_t)8)))
		{
			goto IL_0056;
		}
	}
	{
		RuntimeObject* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		RuntimeObject* L_12 = L_11;
		if (L_12)
		{
			G_B4_0 = L_12;
			goto IL_0048;
		}
		G_B3_0 = L_12;
	}
	{
		goto IL_0054;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_13;
		L_13 = Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline(Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		NullCheck(G_B4_0);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(1, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)51), L_13);
	}

IL_0054:
	{
		V_3 = 8;
	}

IL_0056:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = V_3;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_16 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, ((int32_t)il2cpp_codegen_multiply(L_15, L_17))));
		int32_t L_18 = V_3;
		switch (((int32_t)il2cpp_codegen_subtract(L_18, 1)))
		{
			case 0:
			{
				goto IL_008c;
			}
			case 1:
			{
				goto IL_00a5;
			}
			case 2:
			{
				goto IL_00be;
			}
			case 3:
			{
				goto IL_00d4;
			}
			case 4:
			{
				goto IL_00ea;
			}
			case 5:
			{
				goto IL_0100;
			}
			case 6:
			{
				goto IL_0116;
			}
		}
	}
	{
		goto IL_012c;
	}

IL_008c:
	{
		int32_t L_19 = V_3;
		int32_t L_20;
		L_20 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_21 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* L_22 = (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0(L_22, L_19, L_20, L_21, NULL);
		V_7 = L_22;
		goto IL_0140;
	}

IL_00a5:
	{
		int32_t L_23 = V_3;
		int32_t L_24;
		L_24 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_25 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* L_26 = (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE(L_26, L_23, L_24, L_25, NULL);
		V_7 = L_26;
		goto IL_0140;
	}

IL_00be:
	{
		int32_t L_27 = V_3;
		int32_t L_28;
		L_28 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_29 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* L_30 = (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1(L_30, L_27, L_28, L_29, NULL);
		V_7 = L_30;
		goto IL_0140;
	}

IL_00d4:
	{
		int32_t L_31 = V_3;
		int32_t L_32;
		L_32 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_33 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* L_34 = (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9(L_34, L_31, L_32, L_33, NULL);
		V_7 = L_34;
		goto IL_0140;
	}

IL_00ea:
	{
		int32_t L_35 = V_3;
		int32_t L_36;
		L_36 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_37 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* L_38 = (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333(L_38, L_35, L_36, L_37, NULL);
		V_7 = L_38;
		goto IL_0140;
	}

IL_0100:
	{
		int32_t L_39 = V_3;
		int32_t L_40;
		L_40 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_41 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* L_42 = (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5(L_42, L_39, L_40, L_41, NULL);
		V_7 = L_42;
		goto IL_0140;
	}

IL_0116:
	{
		int32_t L_43 = V_3;
		int32_t L_44;
		L_44 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_45 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* L_46 = (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19(L_46, L_43, L_44, L_45, NULL);
		V_7 = L_46;
		goto IL_0140;
	}

IL_012c:
	{
		int32_t L_47 = V_3;
		int32_t L_48;
		L_48 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_49 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* L_50 = (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016(L_50, L_47, L_48, L_49, NULL);
		V_7 = L_50;
	}

IL_0140:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_51 = V_7;
		__this->___m_TexCoords = L_51;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_TexCoords), (void*)L_51);
	}

IL_0148:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_52 = V_2;
		NullCheck(L_52);
		int32_t L_53 = L_52->___COLOR_0;
		__this->___m_HasColors = (bool)((((int32_t)((((int32_t)L_53) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_54 = __this->___m_HasColors;
		if (!L_54)
		{
			goto IL_0184;
		}
	}
	{
		int32_t L_55 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_56 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_56);
		int32_t L_57 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_56)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_55, L_57));
		int32_t L_58;
		L_58 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_59 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_60 = (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA*)il2cpp_codegen_object_new(VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C(L_60, L_58, L_59, NULL);
		__this->___m_Colors = L_60;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Colors), (void*)L_60);
	}

IL_0184:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_61 = V_2;
		NullCheck(L_61);
		int32_t L_62 = L_61->___WEIGHTS_0;
		if ((((int32_t)L_62) < ((int32_t)0)))
		{
			G_B21_0 = __this;
			goto IL_019c;
		}
		G_B20_0 = __this;
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_63 = V_2;
		NullCheck(L_63);
		int32_t L_64 = L_63->___JOINTS_0;
		G_B22_0 = ((((int32_t)((((int32_t)L_64) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		G_B22_1 = G_B20_0;
		goto IL_019d;
	}

IL_019c:
	{
		G_B22_0 = 0;
		G_B22_1 = G_B21_0;
	}

IL_019d:
	{
		NullCheck(G_B22_1);
		G_B22_1->___m_HasBones = (bool)G_B22_0;
		bool L_65 = __this->___m_HasBones;
		if (!L_65)
		{
			goto IL_01c5;
		}
	}
	{
		int32_t L_66 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_66, 1));
		int32_t L_67;
		L_67 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_68 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_69 = (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94*)il2cpp_codegen_object_new(VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D(L_69, L_67, L_68, NULL);
		__this->___m_Bones = L_69;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Bones), (void*)L_69);
	}

IL_01c5:
	{
		V_8 = 0;
		goto IL_0252;
	}

IL_01cd:
	{
		int32_t L_70 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_70, 1));
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_71 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_72 = V_8;
		NullCheck(L_71);
		int32_t L_73 = L_72;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_74 = (L_71)->GetAt(static_cast<il2cpp_array_size_t>(L_73));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_75 = __this->___m_PositionAccessors;
		int32_t L_76 = V_8;
		NullCheck(L_75);
		int32_t L_77 = L_76;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_78 = (L_75)->GetAt(static_cast<il2cpp_array_size_t>(L_77));
		NullCheck(L_78);
		bool L_79;
		L_79 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_78, NULL);
		if (!L_79)
		{
			G_B28_0 = L_74;
			goto IL_01ff;
		}
		G_B26_0 = L_74;
	}
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_80 = __this->___m_PositionAccessors;
		int32_t L_81 = V_8;
		NullCheck(L_80);
		int32_t L_82 = L_81;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_83 = (L_80)->GetAt(static_cast<il2cpp_array_size_t>(L_82));
		NullCheck(L_83);
		int32_t L_84 = L_83->___bufferView;
		if ((((int32_t)L_84) < ((int32_t)0)))
		{
			G_B28_0 = G_B26_0;
			goto IL_01ff;
		}
		G_B27_0 = G_B26_0;
	}
	{
		int32_t L_85 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_85, 1));
		G_B28_0 = G_B27_0;
	}

IL_01ff:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_86 = G_B28_0;
		NullCheck(L_86);
		int32_t L_87 = L_86->___NORMAL;
		if ((((int32_t)L_87) < ((int32_t)0)))
		{
			G_B30_0 = L_86;
			goto IL_0213;
		}
		G_B29_0 = L_86;
	}
	{
		int32_t L_88 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_88, 1));
		__this->___m_HasNormals = (bool)1;
		G_B30_0 = G_B29_0;
	}

IL_0213:
	{
		bool L_89 = __this->___m_HasNormals;
		bool L_90 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateNormals;
		__this->___m_HasNormals = (bool)((int32_t)((int32_t)L_89|(int32_t)L_90));
		NullCheck(G_B30_0);
		int32_t L_91 = G_B30_0->___TANGENT;
		if ((((int32_t)L_91) < ((int32_t)0)))
		{
			goto IL_0239;
		}
	}
	{
		int32_t L_92 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_92, 1));
		__this->___m_HasTangents = (bool)1;
	}

IL_0239:
	{
		bool L_93 = __this->___m_HasTangents;
		bool L_94 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateTangents;
		__this->___m_HasTangents = (bool)((int32_t)((int32_t)L_93|(int32_t)L_94));
		int32_t L_95 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_95, 1));
	}

IL_0252:
	{
		int32_t L_96 = V_8;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_97 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_97);
		int32_t L_98 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_97)->max_length),NULL));
		if ((((int32_t)L_96) < ((int32_t)L_98)))
		{
			goto IL_01cd;
		}
	}
	{
		int32_t L_99 = V_1;
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_4), L_99, 4, 1, NULL);
		V_5 = 0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_100 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 3)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_101;
		L_101 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_100, NULL);
		CHECKED_LOCAL_INIT(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit,(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_102;
		L_102 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_101, NULL);
		V_6 = L_102;
		V_9 = 0;
		goto IL_0340;
	}

IL_0287:
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_103 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_104 = V_9;
		NullCheck(L_103);
		int32_t L_105 = L_104;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_106 = (L_103)->GetAt(static_cast<il2cpp_array_size_t>(L_105));
		V_10 = L_106;
		int32_t L_107 = V_9;
		uint8_t* L_108 = V_0;
		int32_t L_109 = V_6;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_110 = V_4;
		bool L_111;
		L_111 = VertexBufferGenerator_1_SchedulePositionsJobs_mF6C412F9AE54E68C390D715FD61E39EA0B1104C1(__this, L_107, L_108, L_109, L_110, (&V_5), NULL);
		if (L_111)
		{
			goto IL_02ae;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_112 = V_11;
		return L_112;
	}

IL_02ae:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_113 = V_10;
		NullCheck(L_113);
		int32_t L_114 = L_113->___NORMAL;
		if ((((int32_t)L_114) < ((int32_t)0)))
		{
			goto IL_02d6;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_115 = V_10;
		uint8_t* L_116 = V_0;
		int32_t L_117 = V_6;
		int32_t L_118 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_119 = V_4;
		bool L_120;
		L_120 = VertexBufferGenerator_1_ScheduleNormalsJobs_m759C2CDD45A3A7E6BBB0FFE983E33A6E7D248136(__this, L_115, L_116, L_117, L_118, L_119, (&V_5), NULL);
		if (L_120)
		{
			goto IL_02d6;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_121 = V_11;
		return L_121;
	}

IL_02d6:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_122 = V_10;
		NullCheck(L_122);
		int32_t L_123 = L_122->___TANGENT;
		if ((((int32_t)L_123) < ((int32_t)0)))
		{
			goto IL_02fe;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_124 = V_10;
		uint8_t* L_125 = V_0;
		int32_t L_126 = V_6;
		int32_t L_127 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_128 = V_4;
		bool L_129;
		L_129 = VertexBufferGenerator_1_ScheduleTangentsJobs_m4D2957E9D254DF24797C4572CAE523501105225D(__this, L_124, L_125, L_126, L_127, L_128, (&V_5), NULL);
		if (L_129)
		{
			goto IL_02fe;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_130 = V_11;
		return L_130;
	}

IL_02fe:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_131 = __this->___m_TexCoords;
		if (!L_131)
		{
			goto IL_0317;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_132 = V_10;
		int32_t L_133 = V_3;
		int32_t L_134 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_135 = V_4;
		int32_t L_136 = V_5;
		int32_t L_137;
		L_137 = VertexBufferGenerator_1_ScheduleTexCoordJobs_m5B614A1018475BC3C9AE872EBB9E1AF42273AF7B(__this, L_132, L_133, L_134, L_135, L_136, NULL);
		V_5 = L_137;
	}

IL_0317:
	{
		bool L_138 = __this->___m_HasColors;
		if (!L_138)
		{
			goto IL_033a;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_139 = V_10;
		int32_t L_140 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_141 = V_4;
		bool L_142;
		L_142 = VertexBufferGenerator_1_ScheduleColorsJobs_mB67927A5E7B9EB64C6BDCE399C0C3FED1243331A(__this, L_139, L_140, L_141, (&V_5), NULL);
		if (L_142)
		{
			goto IL_033a;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_143 = V_11;
		return L_143;
	}

IL_033a:
	{
		int32_t L_144 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_144, 1));
	}

IL_0340:
	{
		int32_t L_145 = V_9;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_146 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_146);
		int32_t L_147 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_146)->max_length),NULL));
		if ((((int32_t)L_145) < ((int32_t)L_147)))
		{
			goto IL_0287;
		}
	}
	{
		bool L_148 = __this->___m_HasBones;
		if (!L_148)
		{
			goto IL_037a;
		}
	}
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_149 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_150 = V_5;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_151;
		L_151 = NativeArray_1_GetSubArray_mA9C8FA837D0A861E42C28E31C02AF86688C0801E((&V_4), L_150, 1, NULL);
		bool L_152;
		L_152 = VertexBufferGenerator_1_ScheduleVertexBonesJobs_mFB6B5196F674BE1200C6428109149A88F30003A7(__this, L_149, L_151, NULL);
		if (L_152)
		{
			goto IL_037a;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_153 = V_11;
		return L_153;
	}

IL_037a:
	{
		int32_t L_154 = V_1;
		if ((((int32_t)L_154) > ((int32_t)1)))
		{
			goto IL_0388;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_155;
		L_155 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_4))->___m_Buffer, 0);
		G_B56_0 = L_155;
		goto IL_038f;
	}

IL_0388:
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_156 = V_4;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_157;
		L_157 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_156, NULL);
		G_B56_0 = L_157;
	}

IL_038f:
	{
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_4), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_158;
		memset((&L_158), 0, sizeof(L_158));
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&L_158), G_B56_0, NULL);
		return L_158;
	}
}
// Method Definition Index: 58116
// Method Definition Index: 58117
// Method Definition Index: 58118
// Method Definition Index: 58119
// Method Definition Index: 58120
// Method Definition Index: 58121
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_mFB6B5196F674BE1200C6428109149A88F30003A7 (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	U3CU3Ec__DisplayClass27_0_t98931B9A9F5702BFC6578F521C2F0866E10CC06D V_0;
	memset((&V_0), 0, sizeof(V_0));
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_3;
	memset((&V_3), 0, sizeof(V_3));
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_4;
	memset((&V_4), 0, sizeof(V_4));
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_0 = ___0_attributes;
		(&V_0)->___attributes = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___attributes), (void*)L_0);
		(&V_0)->___U3CU3E4__this = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___U3CU3E4__this), (void*)__this);
		U3CU3Ec__DisplayClass27_0_t98931B9A9F5702BFC6578F521C2F0866E10CC06D L_1 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_2 = L_1.___attributes;
		NullCheck(L_2);
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((((int32_t)L_3) <= ((int32_t)1)))
		{
			goto IL_006e;
		}
	}
	{
		U3CU3Ec__DisplayClass27_0_t98931B9A9F5702BFC6578F521C2F0866E10CC06D L_4 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_5 = L_4.___attributes;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_1), L_6, 2, 1, NULL);
		V_2 = 0;
		goto IL_004c;
	}

IL_0030:
	{
		int32_t L_7 = V_2;
		bool L_8;
		L_8 = VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_m30D6D89C36F1308DC8C04906CDC86F9F312F885C(__this, L_7, (&V_3), (&V_0), NULL);
		if (L_8)
		{
			goto IL_003f;
		}
	}
	{
		return (bool)0;
	}

IL_003f:
	{
		int32_t L_9 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_10 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_1))->___m_Buffer, L_9, (L_10));
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_004c:
	{
		int32_t L_12 = V_2;
		U3CU3Ec__DisplayClass27_0_t98931B9A9F5702BFC6578F521C2F0866E10CC06D L_13 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_14 = L_13.___attributes;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_12) < ((int32_t)L_15)))
		{
			goto IL_0030;
		}
	}
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_16 = V_1;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_17;
		L_17 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_16, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_17));
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_1), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		goto IL_0087;
	}

IL_006e:
	{
		bool L_18;
		L_18 = VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_m30D6D89C36F1308DC8C04906CDC86F9F312F885C(__this, 0, (&V_4), (&V_0), NULL);
		if (L_18)
		{
			goto IL_007d;
		}
	}
	{
		return (bool)0;
	}

IL_007d:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_19 = V_4;
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_19));
	}

IL_0087:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_20 = __this->___m_Bones;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_21;
		L_21 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0);
		NullCheck(L_20);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_22;
		L_22 = VertexBufferBones_ScheduleSortAndNormalizeBoneWeightsJob_mD358C4D61558BCB09ACFD05E2D32014CAD205835(L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_22));
		return (bool)1;
	}
}
// Method Definition Index: 58122
// Method Definition Index: 58123
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_ApplyOnMesh_mEF2EA511BF57F0C2FCD1A8778CFA38E786C5042A (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_flags, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		VertexBufferGenerator_1_CreateDescriptors_m61EB63159D587C7438A2610FCEA2BA5E5AD603A7(__this, NULL);
	}

IL_000e:
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_1 = ___0_msh;
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* L_2 = (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		NullCheck(L_1);
		Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2(L_1, L_3, L_4, NULL);
		V_0 = 0;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_5 = ___0_msh;
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32 L_6 = __this->___m_Data;
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* L_7 = (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*)(&__this->___m_Data);
		int32_t L_8;
		L_8 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_7)->___m_Length);
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_flags;
		NullCheck(L_5);
		Mesh_SetVertexBufferData_TisVPos_t60F9F86213E6426227874FBBA41EF5551B920A72_mDB8D148A0EF2CE914022B139EDC228BC42BA980D(L_5, L_6, 0, 0, L_8, L_9, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_12 = __this->___m_Colors;
		if (!L_12)
		{
			goto IL_0060;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_13 = __this->___m_Colors;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_14 = ___0_msh;
		int32_t L_15 = V_0;
		int32_t L_16 = ___1_flags;
		NullCheck(L_13);
		VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198(L_13, L_14, L_15, L_16, NULL);
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0060:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_18 = __this->___m_TexCoords;
		if (!L_18)
		{
			goto IL_007a;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_19 = __this->___m_TexCoords;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_20 = ___0_msh;
		int32_t L_21 = V_0;
		int32_t L_22 = ___1_flags;
		NullCheck(L_19);
		VirtualActionInvoker3< Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, int32_t, int32_t >::Invoke(7, L_19, L_20, L_21, L_22);
		int32_t L_23 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007a:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_24 = __this->___m_Bones;
		if (!L_24)
		{
			goto IL_0090;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_25 = __this->___m_Bones;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_26 = ___0_msh;
		int32_t L_27 = V_0;
		int32_t L_28 = ___1_flags;
		NullCheck(L_25);
		VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799(L_25, L_26, L_27, L_28, NULL);
	}

IL_0090:
	{
		return;
	}
}
// Method Definition Index: 58124
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Dispose_mA5FE5442E3B7D5BD915EB52D766C9814F024210D (VertexBufferGenerator_1_t9537486469E487B2EC38A8F4D8097D69803F557B* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B5_0 = NULL;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B4_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B8_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B7_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B11_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B10_0 = NULL;
	{
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* L_0 = (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_m6492C57B05D6B9FFD26772B944B2A6BEF6015483_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32* L_2 = (NativeArray_1_tD408100FF3EF35A33487FCC54E51BA9B32EE3C32*)(&__this->___m_Data);
		NativeArray_1_Dispose_m6BDF1E860A988B4B255D8FDF639C0C4D8B2FA788(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16));
	}

IL_0018:
	{
		bool L_3 = ___0_disposing;
		if (!L_3)
		{
			goto IL_004d;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_4 = __this->___m_Colors;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_5 = L_4;
		if (L_5)
		{
			G_B5_0 = L_5;
			goto IL_0027;
		}
		G_B4_0 = L_5;
	}
	{
		goto IL_002c;
	}

IL_0027:
	{
		NullCheck(G_B5_0);
		VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163(G_B5_0, NULL);
	}

IL_002c:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_7 = L_6;
		if (L_7)
		{
			G_B8_0 = L_7;
			goto IL_0038;
		}
		G_B7_0 = L_7;
	}
	{
		goto IL_003d;
	}

IL_0038:
	{
		NullCheck(G_B8_0);
		VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04(G_B8_0, NULL);
	}

IL_003d:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_8 = __this->___m_Bones;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_9 = L_8;
		if (L_9)
		{
			G_B11_0 = L_9;
			goto IL_0048;
		}
		G_B10_0 = L_9;
	}
	{
		return;
	}

IL_0048:
	{
		NullCheck(G_B11_0);
		VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E(G_B11_0, NULL);
	}

IL_004d:
	{
		return;
	}
}
// Method Definition Index: 58125
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 58106
// Method Definition Index: 58107
// Method Definition Index: 58108
// Method Definition Index: 58109
// Method Definition Index: 58110
// Method Definition Index: 58111
// Method Definition Index: 58112
// Method Definition Index: 58113
// Method Definition Index: 58114
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t824317F4B958F7512E8F7300511752937A6C6043* VertexBufferGenerator_1_CreateVertexBuffer_m711CD0902CB06AFB6D928E099A009A2041971F37 (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_StaticInit);
	//<source_info:<no-source>:1>
	U3CCreateVertexBufferU3Ed__20_tDADD490A251616C2620B0CB2C503DFC0198E7D6A V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CHECKED_LOCAL_INIT(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_StaticInit,(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA L_0;
		L_0 = AsyncTaskMethodBuilder_1_Create_mA86694527610A40A01A943B16F0ECDDD8F00982D(NULL);
		(&V_0)->___U3CU3Et__builder = L_0;
		Il2CppCodeGenWriteBarrier((void**)&((&(((&(&V_0)->___U3CU3Et__builder))->___m_coreState))->___m_stateMachine), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&(&V_0)->___U3CU3Et__builder))->___m_coreState))->___m_defaultContextAction), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&(&V_0)->___U3CU3Et__builder))->___m_task), (void*)NULL);
		#endif
		(&V_0)->___U3CU3E4__this = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___U3CU3E4__this), (void*)__this);
		(&V_0)->___U3CU3E1__state = (-1);
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* L_1 = (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA*)(&(&V_0)->___U3CU3Et__builder);
		AsyncTaskMethodBuilder_1_Start_TisU3CCreateVertexBufferU3Ed__20_tDADD490A251616C2620B0CB2C503DFC0198E7D6A_mCDF95461FA64637CA4378B4284931B452FB943CB(L_1, (&V_0), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* L_2 = (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA*)(&(&V_0)->___U3CU3Et__builder);
		Task_1_t824317F4B958F7512E8F7300511752937A6C6043* L_3;
		L_3 = AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943(L_2, AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943_RuntimeMethod_var);
		return L_3;
	}
}
// Method Definition Index: 58115
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGenerator_1_CreateVertexBufferHandle_mB37F7B9F8599489442C93AC5C0B958D016B7444C (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	CHECKED_LOCAL(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_2 = NULL;
	int32_t V_3 = 0;
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_10 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_11;
	memset((&V_11), 0, sizeof(V_11));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* G_B21_0 = NULL;
	VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* G_B20_0 = NULL;
	int32_t G_B22_0 = 0;
	VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* G_B22_1 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B28_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B26_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B27_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B30_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B29_0 = NULL;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 G_B56_0;
	memset((&G_B56_0), 0, sizeof(G_B56_0));
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E L_1;
		memset((&L_1), 0, sizeof(L_1));
		NativeArray_1__ctor_m6ED28625050D6187E9FF635F2F0B84FAE98963DE((&L_1), L_0, 4, 1, NULL);
		__this->___m_Data = L_1;
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E L_2 = __this->___m_Data;
		void* L_3;
		L_3 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_mEF24F47840037840AEF8626D31E8C4C54CEF3340_inline(L_2, NULL);
		V_0 = (uint8_t*)L_3;
		V_1 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_4);
		int32_t L_5 = 0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_6 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		V_2 = L_6;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_7 = V_2;
		NullCheck(L_7);
		int32_t L_8;
		L_8 = Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7(L_7, NULL);
		V_3 = L_8;
		int32_t L_9 = V_3;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0148;
		}
	}
	{
		int32_t L_10 = V_3;
		if ((((int32_t)L_10) <= ((int32_t)8)))
		{
			goto IL_0056;
		}
	}
	{
		RuntimeObject* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		RuntimeObject* L_12 = L_11;
		if (L_12)
		{
			G_B4_0 = L_12;
			goto IL_0048;
		}
		G_B3_0 = L_12;
	}
	{
		goto IL_0054;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_13;
		L_13 = Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline(Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		NullCheck(G_B4_0);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(1, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)51), L_13);
	}

IL_0054:
	{
		V_3 = 8;
	}

IL_0056:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = V_3;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_16 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, ((int32_t)il2cpp_codegen_multiply(L_15, L_17))));
		int32_t L_18 = V_3;
		switch (((int32_t)il2cpp_codegen_subtract(L_18, 1)))
		{
			case 0:
			{
				goto IL_008c;
			}
			case 1:
			{
				goto IL_00a5;
			}
			case 2:
			{
				goto IL_00be;
			}
			case 3:
			{
				goto IL_00d4;
			}
			case 4:
			{
				goto IL_00ea;
			}
			case 5:
			{
				goto IL_0100;
			}
			case 6:
			{
				goto IL_0116;
			}
		}
	}
	{
		goto IL_012c;
	}

IL_008c:
	{
		int32_t L_19 = V_3;
		int32_t L_20;
		L_20 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_21 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* L_22 = (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0(L_22, L_19, L_20, L_21, NULL);
		V_7 = L_22;
		goto IL_0140;
	}

IL_00a5:
	{
		int32_t L_23 = V_3;
		int32_t L_24;
		L_24 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_25 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* L_26 = (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE(L_26, L_23, L_24, L_25, NULL);
		V_7 = L_26;
		goto IL_0140;
	}

IL_00be:
	{
		int32_t L_27 = V_3;
		int32_t L_28;
		L_28 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_29 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* L_30 = (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1(L_30, L_27, L_28, L_29, NULL);
		V_7 = L_30;
		goto IL_0140;
	}

IL_00d4:
	{
		int32_t L_31 = V_3;
		int32_t L_32;
		L_32 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_33 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* L_34 = (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9(L_34, L_31, L_32, L_33, NULL);
		V_7 = L_34;
		goto IL_0140;
	}

IL_00ea:
	{
		int32_t L_35 = V_3;
		int32_t L_36;
		L_36 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_37 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* L_38 = (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333(L_38, L_35, L_36, L_37, NULL);
		V_7 = L_38;
		goto IL_0140;
	}

IL_0100:
	{
		int32_t L_39 = V_3;
		int32_t L_40;
		L_40 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_41 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* L_42 = (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5(L_42, L_39, L_40, L_41, NULL);
		V_7 = L_42;
		goto IL_0140;
	}

IL_0116:
	{
		int32_t L_43 = V_3;
		int32_t L_44;
		L_44 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_45 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* L_46 = (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19(L_46, L_43, L_44, L_45, NULL);
		V_7 = L_46;
		goto IL_0140;
	}

IL_012c:
	{
		int32_t L_47 = V_3;
		int32_t L_48;
		L_48 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_49 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* L_50 = (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016(L_50, L_47, L_48, L_49, NULL);
		V_7 = L_50;
	}

IL_0140:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_51 = V_7;
		__this->___m_TexCoords = L_51;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_TexCoords), (void*)L_51);
	}

IL_0148:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_52 = V_2;
		NullCheck(L_52);
		int32_t L_53 = L_52->___COLOR_0;
		__this->___m_HasColors = (bool)((((int32_t)((((int32_t)L_53) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_54 = __this->___m_HasColors;
		if (!L_54)
		{
			goto IL_0184;
		}
	}
	{
		int32_t L_55 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_56 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_56);
		int32_t L_57 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_56)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_55, L_57));
		int32_t L_58;
		L_58 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_59 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_60 = (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA*)il2cpp_codegen_object_new(VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C(L_60, L_58, L_59, NULL);
		__this->___m_Colors = L_60;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Colors), (void*)L_60);
	}

IL_0184:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_61 = V_2;
		NullCheck(L_61);
		int32_t L_62 = L_61->___WEIGHTS_0;
		if ((((int32_t)L_62) < ((int32_t)0)))
		{
			G_B21_0 = __this;
			goto IL_019c;
		}
		G_B20_0 = __this;
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_63 = V_2;
		NullCheck(L_63);
		int32_t L_64 = L_63->___JOINTS_0;
		G_B22_0 = ((((int32_t)((((int32_t)L_64) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		G_B22_1 = G_B20_0;
		goto IL_019d;
	}

IL_019c:
	{
		G_B22_0 = 0;
		G_B22_1 = G_B21_0;
	}

IL_019d:
	{
		NullCheck(G_B22_1);
		G_B22_1->___m_HasBones = (bool)G_B22_0;
		bool L_65 = __this->___m_HasBones;
		if (!L_65)
		{
			goto IL_01c5;
		}
	}
	{
		int32_t L_66 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_66, 1));
		int32_t L_67;
		L_67 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_68 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_69 = (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94*)il2cpp_codegen_object_new(VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D(L_69, L_67, L_68, NULL);
		__this->___m_Bones = L_69;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Bones), (void*)L_69);
	}

IL_01c5:
	{
		V_8 = 0;
		goto IL_0252;
	}

IL_01cd:
	{
		int32_t L_70 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_70, 1));
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_71 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_72 = V_8;
		NullCheck(L_71);
		int32_t L_73 = L_72;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_74 = (L_71)->GetAt(static_cast<il2cpp_array_size_t>(L_73));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_75 = __this->___m_PositionAccessors;
		int32_t L_76 = V_8;
		NullCheck(L_75);
		int32_t L_77 = L_76;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_78 = (L_75)->GetAt(static_cast<il2cpp_array_size_t>(L_77));
		NullCheck(L_78);
		bool L_79;
		L_79 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_78, NULL);
		if (!L_79)
		{
			G_B28_0 = L_74;
			goto IL_01ff;
		}
		G_B26_0 = L_74;
	}
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_80 = __this->___m_PositionAccessors;
		int32_t L_81 = V_8;
		NullCheck(L_80);
		int32_t L_82 = L_81;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_83 = (L_80)->GetAt(static_cast<il2cpp_array_size_t>(L_82));
		NullCheck(L_83);
		int32_t L_84 = L_83->___bufferView;
		if ((((int32_t)L_84) < ((int32_t)0)))
		{
			G_B28_0 = G_B26_0;
			goto IL_01ff;
		}
		G_B27_0 = G_B26_0;
	}
	{
		int32_t L_85 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_85, 1));
		G_B28_0 = G_B27_0;
	}

IL_01ff:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_86 = G_B28_0;
		NullCheck(L_86);
		int32_t L_87 = L_86->___NORMAL;
		if ((((int32_t)L_87) < ((int32_t)0)))
		{
			G_B30_0 = L_86;
			goto IL_0213;
		}
		G_B29_0 = L_86;
	}
	{
		int32_t L_88 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_88, 1));
		__this->___m_HasNormals = (bool)1;
		G_B30_0 = G_B29_0;
	}

IL_0213:
	{
		bool L_89 = __this->___m_HasNormals;
		bool L_90 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateNormals;
		__this->___m_HasNormals = (bool)((int32_t)((int32_t)L_89|(int32_t)L_90));
		NullCheck(G_B30_0);
		int32_t L_91 = G_B30_0->___TANGENT;
		if ((((int32_t)L_91) < ((int32_t)0)))
		{
			goto IL_0239;
		}
	}
	{
		int32_t L_92 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_92, 1));
		__this->___m_HasTangents = (bool)1;
	}

IL_0239:
	{
		bool L_93 = __this->___m_HasTangents;
		bool L_94 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateTangents;
		__this->___m_HasTangents = (bool)((int32_t)((int32_t)L_93|(int32_t)L_94));
		int32_t L_95 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_95, 1));
	}

IL_0252:
	{
		int32_t L_96 = V_8;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_97 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_97);
		int32_t L_98 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_97)->max_length),NULL));
		if ((((int32_t)L_96) < ((int32_t)L_98)))
		{
			goto IL_01cd;
		}
	}
	{
		int32_t L_99 = V_1;
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_4), L_99, 4, 1, NULL);
		V_5 = 0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_100 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 3)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_101;
		L_101 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_100, NULL);
		CHECKED_LOCAL_INIT(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit,(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_102;
		L_102 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_101, NULL);
		V_6 = L_102;
		V_9 = 0;
		goto IL_0340;
	}

IL_0287:
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_103 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_104 = V_9;
		NullCheck(L_103);
		int32_t L_105 = L_104;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_106 = (L_103)->GetAt(static_cast<il2cpp_array_size_t>(L_105));
		V_10 = L_106;
		int32_t L_107 = V_9;
		uint8_t* L_108 = V_0;
		int32_t L_109 = V_6;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_110 = V_4;
		bool L_111;
		L_111 = VertexBufferGenerator_1_SchedulePositionsJobs_m7E7DCC6FDC1062FD769A6CE944BA2574F74354AC(__this, L_107, L_108, L_109, L_110, (&V_5), NULL);
		if (L_111)
		{
			goto IL_02ae;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_112 = V_11;
		return L_112;
	}

IL_02ae:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_113 = V_10;
		NullCheck(L_113);
		int32_t L_114 = L_113->___NORMAL;
		if ((((int32_t)L_114) < ((int32_t)0)))
		{
			goto IL_02d6;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_115 = V_10;
		uint8_t* L_116 = V_0;
		int32_t L_117 = V_6;
		int32_t L_118 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_119 = V_4;
		bool L_120;
		L_120 = VertexBufferGenerator_1_ScheduleNormalsJobs_m4A6BA6C3D0065FCE7DEBA556830D0BB2C20F1050(__this, L_115, L_116, L_117, L_118, L_119, (&V_5), NULL);
		if (L_120)
		{
			goto IL_02d6;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_121 = V_11;
		return L_121;
	}

IL_02d6:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_122 = V_10;
		NullCheck(L_122);
		int32_t L_123 = L_122->___TANGENT;
		if ((((int32_t)L_123) < ((int32_t)0)))
		{
			goto IL_02fe;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_124 = V_10;
		uint8_t* L_125 = V_0;
		int32_t L_126 = V_6;
		int32_t L_127 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_128 = V_4;
		bool L_129;
		L_129 = VertexBufferGenerator_1_ScheduleTangentsJobs_m24ED9C3178F6780CE23AF897AEE13B9F83A4E24B(__this, L_124, L_125, L_126, L_127, L_128, (&V_5), NULL);
		if (L_129)
		{
			goto IL_02fe;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_130 = V_11;
		return L_130;
	}

IL_02fe:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_131 = __this->___m_TexCoords;
		if (!L_131)
		{
			goto IL_0317;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_132 = V_10;
		int32_t L_133 = V_3;
		int32_t L_134 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_135 = V_4;
		int32_t L_136 = V_5;
		int32_t L_137;
		L_137 = VertexBufferGenerator_1_ScheduleTexCoordJobs_m5B1B735D20E1FBF67AA5DE4CE83BAC26C59C0A61(__this, L_132, L_133, L_134, L_135, L_136, NULL);
		V_5 = L_137;
	}

IL_0317:
	{
		bool L_138 = __this->___m_HasColors;
		if (!L_138)
		{
			goto IL_033a;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_139 = V_10;
		int32_t L_140 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_141 = V_4;
		bool L_142;
		L_142 = VertexBufferGenerator_1_ScheduleColorsJobs_mC44D082A9C89E72CA01C5D92DE0918F1CADD2304(__this, L_139, L_140, L_141, (&V_5), NULL);
		if (L_142)
		{
			goto IL_033a;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_143 = V_11;
		return L_143;
	}

IL_033a:
	{
		int32_t L_144 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_144, 1));
	}

IL_0340:
	{
		int32_t L_145 = V_9;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_146 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_146);
		int32_t L_147 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_146)->max_length),NULL));
		if ((((int32_t)L_145) < ((int32_t)L_147)))
		{
			goto IL_0287;
		}
	}
	{
		bool L_148 = __this->___m_HasBones;
		if (!L_148)
		{
			goto IL_037a;
		}
	}
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_149 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_150 = V_5;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_151;
		L_151 = NativeArray_1_GetSubArray_mA9C8FA837D0A861E42C28E31C02AF86688C0801E((&V_4), L_150, 1, NULL);
		bool L_152;
		L_152 = VertexBufferGenerator_1_ScheduleVertexBonesJobs_m2846F0D611AC1AF6D33E17DF9FC1F7F4AF44188F(__this, L_149, L_151, NULL);
		if (L_152)
		{
			goto IL_037a;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_153 = V_11;
		return L_153;
	}

IL_037a:
	{
		int32_t L_154 = V_1;
		if ((((int32_t)L_154) > ((int32_t)1)))
		{
			goto IL_0388;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_155;
		L_155 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_4))->___m_Buffer, 0);
		G_B56_0 = L_155;
		goto IL_038f;
	}

IL_0388:
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_156 = V_4;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_157;
		L_157 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_156, NULL);
		G_B56_0 = L_157;
	}

IL_038f:
	{
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_4), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_158;
		memset((&L_158), 0, sizeof(L_158));
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&L_158), G_B56_0, NULL);
		return L_158;
	}
}
// Method Definition Index: 58116
// Method Definition Index: 58117
// Method Definition Index: 58118
// Method Definition Index: 58119
// Method Definition Index: 58120
// Method Definition Index: 58121
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m2846F0D611AC1AF6D33E17DF9FC1F7F4AF44188F (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	U3CU3Ec__DisplayClass27_0_t705F2B87E06B0436D7006CE67E66CE05E9E61926 V_0;
	memset((&V_0), 0, sizeof(V_0));
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_3;
	memset((&V_3), 0, sizeof(V_3));
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_4;
	memset((&V_4), 0, sizeof(V_4));
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_0 = ___0_attributes;
		(&V_0)->___attributes = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___attributes), (void*)L_0);
		(&V_0)->___U3CU3E4__this = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___U3CU3E4__this), (void*)__this);
		U3CU3Ec__DisplayClass27_0_t705F2B87E06B0436D7006CE67E66CE05E9E61926 L_1 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_2 = L_1.___attributes;
		NullCheck(L_2);
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((((int32_t)L_3) <= ((int32_t)1)))
		{
			goto IL_006e;
		}
	}
	{
		U3CU3Ec__DisplayClass27_0_t705F2B87E06B0436D7006CE67E66CE05E9E61926 L_4 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_5 = L_4.___attributes;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_1), L_6, 2, 1, NULL);
		V_2 = 0;
		goto IL_004c;
	}

IL_0030:
	{
		int32_t L_7 = V_2;
		bool L_8;
		L_8 = VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_m6A1872C9E568642666DA85D454871742EB7A9B7E(__this, L_7, (&V_3), (&V_0), NULL);
		if (L_8)
		{
			goto IL_003f;
		}
	}
	{
		return (bool)0;
	}

IL_003f:
	{
		int32_t L_9 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_10 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_1))->___m_Buffer, L_9, (L_10));
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_004c:
	{
		int32_t L_12 = V_2;
		U3CU3Ec__DisplayClass27_0_t705F2B87E06B0436D7006CE67E66CE05E9E61926 L_13 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_14 = L_13.___attributes;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_12) < ((int32_t)L_15)))
		{
			goto IL_0030;
		}
	}
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_16 = V_1;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_17;
		L_17 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_16, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_17));
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_1), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		goto IL_0087;
	}

IL_006e:
	{
		bool L_18;
		L_18 = VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_m6A1872C9E568642666DA85D454871742EB7A9B7E(__this, 0, (&V_4), (&V_0), NULL);
		if (L_18)
		{
			goto IL_007d;
		}
	}
	{
		return (bool)0;
	}

IL_007d:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_19 = V_4;
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_19));
	}

IL_0087:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_20 = __this->___m_Bones;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_21;
		L_21 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0);
		NullCheck(L_20);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_22;
		L_22 = VertexBufferBones_ScheduleSortAndNormalizeBoneWeightsJob_mD358C4D61558BCB09ACFD05E2D32014CAD205835(L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_22));
		return (bool)1;
	}
}
// Method Definition Index: 58122
// Method Definition Index: 58123
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_ApplyOnMesh_m65690618C224E28490D9A61C7F6C80E1EF128D8E (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_flags, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		VertexBufferGenerator_1_CreateDescriptors_m6543578CB5017D6DE58830F12C0B02C149D77C17(__this, NULL);
	}

IL_000e:
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_1 = ___0_msh;
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* L_2 = (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		NullCheck(L_1);
		Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2(L_1, L_3, L_4, NULL);
		V_0 = 0;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_5 = ___0_msh;
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E L_6 = __this->___m_Data;
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* L_7 = (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*)(&__this->___m_Data);
		int32_t L_8;
		L_8 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_7)->___m_Length);
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_flags;
		NullCheck(L_5);
		Mesh_SetVertexBufferData_TisVPosNorm_t83C1B9EC82865A2124605BF69D0D0FD05E611DCD_m98F5B919E464DF0F3ACD4366F3DC57AF2454635E(L_5, L_6, 0, 0, L_8, L_9, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_12 = __this->___m_Colors;
		if (!L_12)
		{
			goto IL_0060;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_13 = __this->___m_Colors;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_14 = ___0_msh;
		int32_t L_15 = V_0;
		int32_t L_16 = ___1_flags;
		NullCheck(L_13);
		VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198(L_13, L_14, L_15, L_16, NULL);
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0060:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_18 = __this->___m_TexCoords;
		if (!L_18)
		{
			goto IL_007a;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_19 = __this->___m_TexCoords;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_20 = ___0_msh;
		int32_t L_21 = V_0;
		int32_t L_22 = ___1_flags;
		NullCheck(L_19);
		VirtualActionInvoker3< Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, int32_t, int32_t >::Invoke(7, L_19, L_20, L_21, L_22);
		int32_t L_23 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007a:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_24 = __this->___m_Bones;
		if (!L_24)
		{
			goto IL_0090;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_25 = __this->___m_Bones;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_26 = ___0_msh;
		int32_t L_27 = V_0;
		int32_t L_28 = ___1_flags;
		NullCheck(L_25);
		VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799(L_25, L_26, L_27, L_28, NULL);
	}

IL_0090:
	{
		return;
	}
}
// Method Definition Index: 58124
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Dispose_m02FDEB15049C12FE217BEF9499004FDE24A9534A (VertexBufferGenerator_1_t4C4B9A53F9F9814A1A8D26AD03D455F0CB4329CA* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B5_0 = NULL;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B4_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B8_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B7_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B11_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B10_0 = NULL;
	{
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* L_0 = (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_mF889FB0A50008701DFF815D51811D6C2FA88D506_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E* L_2 = (NativeArray_1_tAE4A2361DE1DDFE17E8AA1998BB8F49B8473A62E*)(&__this->___m_Data);
		NativeArray_1_Dispose_mF28F15854DB63F91A8E4ECE7E7046833DEECD545(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16));
	}

IL_0018:
	{
		bool L_3 = ___0_disposing;
		if (!L_3)
		{
			goto IL_004d;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_4 = __this->___m_Colors;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_5 = L_4;
		if (L_5)
		{
			G_B5_0 = L_5;
			goto IL_0027;
		}
		G_B4_0 = L_5;
	}
	{
		goto IL_002c;
	}

IL_0027:
	{
		NullCheck(G_B5_0);
		VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163(G_B5_0, NULL);
	}

IL_002c:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_7 = L_6;
		if (L_7)
		{
			G_B8_0 = L_7;
			goto IL_0038;
		}
		G_B7_0 = L_7;
	}
	{
		goto IL_003d;
	}

IL_0038:
	{
		NullCheck(G_B8_0);
		VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04(G_B8_0, NULL);
	}

IL_003d:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_8 = __this->___m_Bones;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_9 = L_8;
		if (L_9)
		{
			G_B11_0 = L_9;
			goto IL_0048;
		}
		G_B10_0 = L_9;
	}
	{
		return;
	}

IL_0048:
	{
		NullCheck(G_B11_0);
		VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E(G_B11_0, NULL);
	}

IL_004d:
	{
		return;
	}
}
// Method Definition Index: 58125
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 58106
// Method Definition Index: 58107
// Method Definition Index: 58108
// Method Definition Index: 58109
// Method Definition Index: 58110
// Method Definition Index: 58111
// Method Definition Index: 58112
// Method Definition Index: 58113
// Method Definition Index: 58114
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t824317F4B958F7512E8F7300511752937A6C6043* VertexBufferGenerator_1_CreateVertexBuffer_m3963C53715B12EF8E725D9469E97F49FFEE179DD (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_StaticInit);
	//<source_info:<no-source>:1>
	U3CCreateVertexBufferU3Ed__20_t498F74500406EE05901BC1C3ED2CDD59B394793A V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CHECKED_LOCAL_INIT(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_StaticInit,(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA L_0;
		L_0 = AsyncTaskMethodBuilder_1_Create_mA86694527610A40A01A943B16F0ECDDD8F00982D(NULL);
		(&V_0)->___U3CU3Et__builder = L_0;
		Il2CppCodeGenWriteBarrier((void**)&((&(((&(&V_0)->___U3CU3Et__builder))->___m_coreState))->___m_stateMachine), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&(&V_0)->___U3CU3Et__builder))->___m_coreState))->___m_defaultContextAction), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&(&V_0)->___U3CU3Et__builder))->___m_task), (void*)NULL);
		#endif
		(&V_0)->___U3CU3E4__this = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___U3CU3E4__this), (void*)__this);
		(&V_0)->___U3CU3E1__state = (-1);
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* L_1 = (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA*)(&(&V_0)->___U3CU3Et__builder);
		AsyncTaskMethodBuilder_1_Start_TisU3CCreateVertexBufferU3Ed__20_t498F74500406EE05901BC1C3ED2CDD59B394793A_mA70E4D00EB60036D398D673AEB15EE6D8F0A6D6F(L_1, (&V_0), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* L_2 = (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA*)(&(&V_0)->___U3CU3Et__builder);
		Task_1_t824317F4B958F7512E8F7300511752937A6C6043* L_3;
		L_3 = AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943(L_2, AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943_RuntimeMethod_var);
		return L_3;
	}
}
// Method Definition Index: 58115
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGenerator_1_CreateVertexBufferHandle_mEBB285B5AB8697531EE488E77A4DAA7071BAA58D (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	CHECKED_LOCAL(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_2 = NULL;
	int32_t V_3 = 0;
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_10 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_11;
	memset((&V_11), 0, sizeof(V_11));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* G_B21_0 = NULL;
	VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* G_B20_0 = NULL;
	int32_t G_B22_0 = 0;
	VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* G_B22_1 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B28_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B26_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B27_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B30_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B29_0 = NULL;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 G_B56_0;
	memset((&G_B56_0), 0, sizeof(G_B56_0));
	{
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 L_1;
		memset((&L_1), 0, sizeof(L_1));
		NativeArray_1__ctor_mB26D6A63E8B3F18A77A5552D357236D2292DDC4B((&L_1), L_0, 4, 1, NULL);
		__this->___m_Data = L_1;
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 L_2 = __this->___m_Data;
		void* L_3;
		L_3 = NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m4DFB73460B0763281BB179BE6CB139906474F02E_inline(L_2, NULL);
		V_0 = (uint8_t*)L_3;
		V_1 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_4);
		int32_t L_5 = 0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_6 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		V_2 = L_6;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_7 = V_2;
		NullCheck(L_7);
		int32_t L_8;
		L_8 = Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7(L_7, NULL);
		V_3 = L_8;
		int32_t L_9 = V_3;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0148;
		}
	}
	{
		int32_t L_10 = V_3;
		if ((((int32_t)L_10) <= ((int32_t)8)))
		{
			goto IL_0056;
		}
	}
	{
		RuntimeObject* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		RuntimeObject* L_12 = L_11;
		if (L_12)
		{
			G_B4_0 = L_12;
			goto IL_0048;
		}
		G_B3_0 = L_12;
	}
	{
		goto IL_0054;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_13;
		L_13 = Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline(Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		NullCheck(G_B4_0);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(1, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)51), L_13);
	}

IL_0054:
	{
		V_3 = 8;
	}

IL_0056:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = V_3;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_16 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, ((int32_t)il2cpp_codegen_multiply(L_15, L_17))));
		int32_t L_18 = V_3;
		switch (((int32_t)il2cpp_codegen_subtract(L_18, 1)))
		{
			case 0:
			{
				goto IL_008c;
			}
			case 1:
			{
				goto IL_00a5;
			}
			case 2:
			{
				goto IL_00be;
			}
			case 3:
			{
				goto IL_00d4;
			}
			case 4:
			{
				goto IL_00ea;
			}
			case 5:
			{
				goto IL_0100;
			}
			case 6:
			{
				goto IL_0116;
			}
		}
	}
	{
		goto IL_012c;
	}

IL_008c:
	{
		int32_t L_19 = V_3;
		int32_t L_20;
		L_20 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_21 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* L_22 = (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0(L_22, L_19, L_20, L_21, NULL);
		V_7 = L_22;
		goto IL_0140;
	}

IL_00a5:
	{
		int32_t L_23 = V_3;
		int32_t L_24;
		L_24 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_25 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* L_26 = (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE(L_26, L_23, L_24, L_25, NULL);
		V_7 = L_26;
		goto IL_0140;
	}

IL_00be:
	{
		int32_t L_27 = V_3;
		int32_t L_28;
		L_28 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_29 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* L_30 = (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1(L_30, L_27, L_28, L_29, NULL);
		V_7 = L_30;
		goto IL_0140;
	}

IL_00d4:
	{
		int32_t L_31 = V_3;
		int32_t L_32;
		L_32 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_33 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* L_34 = (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9(L_34, L_31, L_32, L_33, NULL);
		V_7 = L_34;
		goto IL_0140;
	}

IL_00ea:
	{
		int32_t L_35 = V_3;
		int32_t L_36;
		L_36 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_37 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* L_38 = (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333(L_38, L_35, L_36, L_37, NULL);
		V_7 = L_38;
		goto IL_0140;
	}

IL_0100:
	{
		int32_t L_39 = V_3;
		int32_t L_40;
		L_40 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_41 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* L_42 = (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5(L_42, L_39, L_40, L_41, NULL);
		V_7 = L_42;
		goto IL_0140;
	}

IL_0116:
	{
		int32_t L_43 = V_3;
		int32_t L_44;
		L_44 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_45 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* L_46 = (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19(L_46, L_43, L_44, L_45, NULL);
		V_7 = L_46;
		goto IL_0140;
	}

IL_012c:
	{
		int32_t L_47 = V_3;
		int32_t L_48;
		L_48 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_49 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* L_50 = (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016(L_50, L_47, L_48, L_49, NULL);
		V_7 = L_50;
	}

IL_0140:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_51 = V_7;
		__this->___m_TexCoords = L_51;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_TexCoords), (void*)L_51);
	}

IL_0148:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_52 = V_2;
		NullCheck(L_52);
		int32_t L_53 = L_52->___COLOR_0;
		__this->___m_HasColors = (bool)((((int32_t)((((int32_t)L_53) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_54 = __this->___m_HasColors;
		if (!L_54)
		{
			goto IL_0184;
		}
	}
	{
		int32_t L_55 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_56 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_56);
		int32_t L_57 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_56)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_55, L_57));
		int32_t L_58;
		L_58 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_59 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_60 = (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA*)il2cpp_codegen_object_new(VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C(L_60, L_58, L_59, NULL);
		__this->___m_Colors = L_60;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Colors), (void*)L_60);
	}

IL_0184:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_61 = V_2;
		NullCheck(L_61);
		int32_t L_62 = L_61->___WEIGHTS_0;
		if ((((int32_t)L_62) < ((int32_t)0)))
		{
			G_B21_0 = __this;
			goto IL_019c;
		}
		G_B20_0 = __this;
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_63 = V_2;
		NullCheck(L_63);
		int32_t L_64 = L_63->___JOINTS_0;
		G_B22_0 = ((((int32_t)((((int32_t)L_64) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		G_B22_1 = G_B20_0;
		goto IL_019d;
	}

IL_019c:
	{
		G_B22_0 = 0;
		G_B22_1 = G_B21_0;
	}

IL_019d:
	{
		NullCheck(G_B22_1);
		G_B22_1->___m_HasBones = (bool)G_B22_0;
		bool L_65 = __this->___m_HasBones;
		if (!L_65)
		{
			goto IL_01c5;
		}
	}
	{
		int32_t L_66 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_66, 1));
		int32_t L_67;
		L_67 = VirtualFuncInvoker0< int32_t >::Invoke(9, __this);
		RuntimeObject* L_68 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_69 = (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94*)il2cpp_codegen_object_new(VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D(L_69, L_67, L_68, NULL);
		__this->___m_Bones = L_69;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Bones), (void*)L_69);
	}

IL_01c5:
	{
		V_8 = 0;
		goto IL_0252;
	}

IL_01cd:
	{
		int32_t L_70 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_70, 1));
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_71 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_72 = V_8;
		NullCheck(L_71);
		int32_t L_73 = L_72;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_74 = (L_71)->GetAt(static_cast<il2cpp_array_size_t>(L_73));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_75 = __this->___m_PositionAccessors;
		int32_t L_76 = V_8;
		NullCheck(L_75);
		int32_t L_77 = L_76;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_78 = (L_75)->GetAt(static_cast<il2cpp_array_size_t>(L_77));
		NullCheck(L_78);
		bool L_79;
		L_79 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_78, NULL);
		if (!L_79)
		{
			G_B28_0 = L_74;
			goto IL_01ff;
		}
		G_B26_0 = L_74;
	}
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_80 = __this->___m_PositionAccessors;
		int32_t L_81 = V_8;
		NullCheck(L_80);
		int32_t L_82 = L_81;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_83 = (L_80)->GetAt(static_cast<il2cpp_array_size_t>(L_82));
		NullCheck(L_83);
		int32_t L_84 = L_83->___bufferView;
		if ((((int32_t)L_84) < ((int32_t)0)))
		{
			G_B28_0 = G_B26_0;
			goto IL_01ff;
		}
		G_B27_0 = G_B26_0;
	}
	{
		int32_t L_85 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_85, 1));
		G_B28_0 = G_B27_0;
	}

IL_01ff:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_86 = G_B28_0;
		NullCheck(L_86);
		int32_t L_87 = L_86->___NORMAL;
		if ((((int32_t)L_87) < ((int32_t)0)))
		{
			G_B30_0 = L_86;
			goto IL_0213;
		}
		G_B29_0 = L_86;
	}
	{
		int32_t L_88 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_88, 1));
		__this->___m_HasNormals = (bool)1;
		G_B30_0 = G_B29_0;
	}

IL_0213:
	{
		bool L_89 = __this->___m_HasNormals;
		bool L_90 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateNormals;
		__this->___m_HasNormals = (bool)((int32_t)((int32_t)L_89|(int32_t)L_90));
		NullCheck(G_B30_0);
		int32_t L_91 = G_B30_0->___TANGENT;
		if ((((int32_t)L_91) < ((int32_t)0)))
		{
			goto IL_0239;
		}
	}
	{
		int32_t L_92 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_92, 1));
		__this->___m_HasTangents = (bool)1;
	}

IL_0239:
	{
		bool L_93 = __this->___m_HasTangents;
		bool L_94 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateTangents;
		__this->___m_HasTangents = (bool)((int32_t)((int32_t)L_93|(int32_t)L_94));
		int32_t L_95 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_95, 1));
	}

IL_0252:
	{
		int32_t L_96 = V_8;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_97 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_97);
		int32_t L_98 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_97)->max_length),NULL));
		if ((((int32_t)L_96) < ((int32_t)L_98)))
		{
			goto IL_01cd;
		}
	}
	{
		int32_t L_99 = V_1;
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_4), L_99, 4, 1, NULL);
		V_5 = 0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_100 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 3)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_101;
		L_101 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_100, NULL);
		CHECKED_LOCAL_INIT(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit,(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_102;
		L_102 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_101, NULL);
		V_6 = L_102;
		V_9 = 0;
		goto IL_0340;
	}

IL_0287:
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_103 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_104 = V_9;
		NullCheck(L_103);
		int32_t L_105 = L_104;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_106 = (L_103)->GetAt(static_cast<il2cpp_array_size_t>(L_105));
		V_10 = L_106;
		int32_t L_107 = V_9;
		uint8_t* L_108 = V_0;
		int32_t L_109 = V_6;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_110 = V_4;
		bool L_111;
		L_111 = VertexBufferGenerator_1_SchedulePositionsJobs_mA272F8DC9995E815EDD688721170775AE5283213(__this, L_107, L_108, L_109, L_110, (&V_5), NULL);
		if (L_111)
		{
			goto IL_02ae;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_112 = V_11;
		return L_112;
	}

IL_02ae:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_113 = V_10;
		NullCheck(L_113);
		int32_t L_114 = L_113->___NORMAL;
		if ((((int32_t)L_114) < ((int32_t)0)))
		{
			goto IL_02d6;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_115 = V_10;
		uint8_t* L_116 = V_0;
		int32_t L_117 = V_6;
		int32_t L_118 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_119 = V_4;
		bool L_120;
		L_120 = VertexBufferGenerator_1_ScheduleNormalsJobs_mDF628CAC3BCB5DEDB2AE0FCE853E7DC2FE3C621A(__this, L_115, L_116, L_117, L_118, L_119, (&V_5), NULL);
		if (L_120)
		{
			goto IL_02d6;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_121 = V_11;
		return L_121;
	}

IL_02d6:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_122 = V_10;
		NullCheck(L_122);
		int32_t L_123 = L_122->___TANGENT;
		if ((((int32_t)L_123) < ((int32_t)0)))
		{
			goto IL_02fe;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_124 = V_10;
		uint8_t* L_125 = V_0;
		int32_t L_126 = V_6;
		int32_t L_127 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_128 = V_4;
		bool L_129;
		L_129 = VertexBufferGenerator_1_ScheduleTangentsJobs_m71316553C3BA7A0DD23BBBA9A82FA54D674587FB(__this, L_124, L_125, L_126, L_127, L_128, (&V_5), NULL);
		if (L_129)
		{
			goto IL_02fe;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_130 = V_11;
		return L_130;
	}

IL_02fe:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_131 = __this->___m_TexCoords;
		if (!L_131)
		{
			goto IL_0317;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_132 = V_10;
		int32_t L_133 = V_3;
		int32_t L_134 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_135 = V_4;
		int32_t L_136 = V_5;
		int32_t L_137;
		L_137 = VertexBufferGenerator_1_ScheduleTexCoordJobs_m0F6AC8EC930129564B6EF188169ED570B9566729(__this, L_132, L_133, L_134, L_135, L_136, NULL);
		V_5 = L_137;
	}

IL_0317:
	{
		bool L_138 = __this->___m_HasColors;
		if (!L_138)
		{
			goto IL_033a;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_139 = V_10;
		int32_t L_140 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_141 = V_4;
		bool L_142;
		L_142 = VertexBufferGenerator_1_ScheduleColorsJobs_m2704633CCB9A2628480745DE8991303651C6D68F(__this, L_139, L_140, L_141, (&V_5), NULL);
		if (L_142)
		{
			goto IL_033a;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_143 = V_11;
		return L_143;
	}

IL_033a:
	{
		int32_t L_144 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_144, 1));
	}

IL_0340:
	{
		int32_t L_145 = V_9;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_146 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_146);
		int32_t L_147 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_146)->max_length),NULL));
		if ((((int32_t)L_145) < ((int32_t)L_147)))
		{
			goto IL_0287;
		}
	}
	{
		bool L_148 = __this->___m_HasBones;
		if (!L_148)
		{
			goto IL_037a;
		}
	}
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_149 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_150 = V_5;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_151;
		L_151 = NativeArray_1_GetSubArray_mA9C8FA837D0A861E42C28E31C02AF86688C0801E((&V_4), L_150, 1, NULL);
		bool L_152;
		L_152 = VertexBufferGenerator_1_ScheduleVertexBonesJobs_m409E88D135C578E00B0B9829877F8264B12C9F68(__this, L_149, L_151, NULL);
		if (L_152)
		{
			goto IL_037a;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_153 = V_11;
		return L_153;
	}

IL_037a:
	{
		int32_t L_154 = V_1;
		if ((((int32_t)L_154) > ((int32_t)1)))
		{
			goto IL_0388;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_155;
		L_155 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_4))->___m_Buffer, 0);
		G_B56_0 = L_155;
		goto IL_038f;
	}

IL_0388:
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_156 = V_4;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_157;
		L_157 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_156, NULL);
		G_B56_0 = L_157;
	}

IL_038f:
	{
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_4), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_158;
		memset((&L_158), 0, sizeof(L_158));
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&L_158), G_B56_0, NULL);
		return L_158;
	}
}
// Method Definition Index: 58116
// Method Definition Index: 58117
// Method Definition Index: 58118
// Method Definition Index: 58119
// Method Definition Index: 58120
// Method Definition Index: 58121
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_m409E88D135C578E00B0B9829877F8264B12C9F68 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	U3CU3Ec__DisplayClass27_0_tC9594FC1F4834B802F2F24BD00D5F4FF36F34306 V_0;
	memset((&V_0), 0, sizeof(V_0));
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_3;
	memset((&V_3), 0, sizeof(V_3));
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_4;
	memset((&V_4), 0, sizeof(V_4));
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_0 = ___0_attributes;
		(&V_0)->___attributes = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___attributes), (void*)L_0);
		(&V_0)->___U3CU3E4__this = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___U3CU3E4__this), (void*)__this);
		U3CU3Ec__DisplayClass27_0_tC9594FC1F4834B802F2F24BD00D5F4FF36F34306 L_1 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_2 = L_1.___attributes;
		NullCheck(L_2);
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((((int32_t)L_3) <= ((int32_t)1)))
		{
			goto IL_006e;
		}
	}
	{
		U3CU3Ec__DisplayClass27_0_tC9594FC1F4834B802F2F24BD00D5F4FF36F34306 L_4 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_5 = L_4.___attributes;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_1), L_6, 2, 1, NULL);
		V_2 = 0;
		goto IL_004c;
	}

IL_0030:
	{
		int32_t L_7 = V_2;
		bool L_8;
		L_8 = VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_m96169F75DA19FF2E0BEDB35946C45D7A19949611(__this, L_7, (&V_3), (&V_0), NULL);
		if (L_8)
		{
			goto IL_003f;
		}
	}
	{
		return (bool)0;
	}

IL_003f:
	{
		int32_t L_9 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_10 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_1))->___m_Buffer, L_9, (L_10));
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_004c:
	{
		int32_t L_12 = V_2;
		U3CU3Ec__DisplayClass27_0_tC9594FC1F4834B802F2F24BD00D5F4FF36F34306 L_13 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_14 = L_13.___attributes;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_12) < ((int32_t)L_15)))
		{
			goto IL_0030;
		}
	}
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_16 = V_1;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_17;
		L_17 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_16, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_17));
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_1), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		goto IL_0087;
	}

IL_006e:
	{
		bool L_18;
		L_18 = VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_m96169F75DA19FF2E0BEDB35946C45D7A19949611(__this, 0, (&V_4), (&V_0), NULL);
		if (L_18)
		{
			goto IL_007d;
		}
	}
	{
		return (bool)0;
	}

IL_007d:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_19 = V_4;
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_19));
	}

IL_0087:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_20 = __this->___m_Bones;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_21;
		L_21 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0);
		NullCheck(L_20);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_22;
		L_22 = VertexBufferBones_ScheduleSortAndNormalizeBoneWeightsJob_mD358C4D61558BCB09ACFD05E2D32014CAD205835(L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_22));
		return (bool)1;
	}
}
// Method Definition Index: 58122
// Method Definition Index: 58123
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_ApplyOnMesh_mAF8B8C9784C11E8242C6FC610DB23B50FC5C78F5 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_flags, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		VertexBufferGenerator_1_CreateDescriptors_m615516608A7DCDC74BE1B06896D86163FB7D9173(__this, NULL);
	}

IL_000e:
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_1 = ___0_msh;
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* L_2 = (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_2)->___m_Length);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		NullCheck(L_1);
		Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2(L_1, L_3, L_4, NULL);
		V_0 = 0;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_5 = ___0_msh;
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250 L_6 = __this->___m_Data;
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* L_7 = (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*)(&__this->___m_Data);
		int32_t L_8;
		L_8 = IL2CPP_NATIVEARRAY_GET_LENGTH((L_7)->___m_Length);
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_flags;
		NullCheck(L_5);
		Mesh_SetVertexBufferData_TisVPosNormTan_tB869C784FC0363C61B0A9F2BC0A20C6C2233D193_m5C4B829BA2A5130FB5C09B29AD8805155EA7C756(L_5, L_6, 0, 0, L_8, L_9, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_12 = __this->___m_Colors;
		if (!L_12)
		{
			goto IL_0060;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_13 = __this->___m_Colors;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_14 = ___0_msh;
		int32_t L_15 = V_0;
		int32_t L_16 = ___1_flags;
		NullCheck(L_13);
		VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198(L_13, L_14, L_15, L_16, NULL);
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0060:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_18 = __this->___m_TexCoords;
		if (!L_18)
		{
			goto IL_007a;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_19 = __this->___m_TexCoords;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_20 = ___0_msh;
		int32_t L_21 = V_0;
		int32_t L_22 = ___1_flags;
		NullCheck(L_19);
		VirtualActionInvoker3< Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, int32_t, int32_t >::Invoke(7, L_19, L_20, L_21, L_22);
		int32_t L_23 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007a:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_24 = __this->___m_Bones;
		if (!L_24)
		{
			goto IL_0090;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_25 = __this->___m_Bones;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_26 = ___0_msh;
		int32_t L_27 = V_0;
		int32_t L_28 = ___1_flags;
		NullCheck(L_25);
		VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799(L_25, L_26, L_27, L_28, NULL);
	}

IL_0090:
	{
		return;
	}
}
// Method Definition Index: 58124
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Dispose_m3B15E3D704EF350ACBA0EBFB53B709A7B9218855 (VertexBufferGenerator_1_tB1175C2AE845EEA9ACE69D841F006DC553C5F32A* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B5_0 = NULL;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B4_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B8_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B7_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B11_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B10_0 = NULL;
	{
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* L_0 = (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*)(&__this->___m_Data);
		bool L_1;
		L_1 = NativeArray_1_get_IsCreated_mC5ED66430AE33CD749E7A37DF7B48DFB49976CC7_inline(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250* L_2 = (NativeArray_1_tD350E73A402290EB7A41B128AE52B5FEFF502250*)(&__this->___m_Data);
		NativeArray_1_Dispose_m82995B1021A45DA3ADE8B42EB36038FBB092EEAF(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16));
	}

IL_0018:
	{
		bool L_3 = ___0_disposing;
		if (!L_3)
		{
			goto IL_004d;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_4 = __this->___m_Colors;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_5 = L_4;
		if (L_5)
		{
			G_B5_0 = L_5;
			goto IL_0027;
		}
		G_B4_0 = L_5;
	}
	{
		goto IL_002c;
	}

IL_0027:
	{
		NullCheck(G_B5_0);
		VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163(G_B5_0, NULL);
	}

IL_002c:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_7 = L_6;
		if (L_7)
		{
			G_B8_0 = L_7;
			goto IL_0038;
		}
		G_B7_0 = L_7;
	}
	{
		goto IL_003d;
	}

IL_0038:
	{
		NullCheck(G_B8_0);
		VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04(G_B8_0, NULL);
	}

IL_003d:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_8 = __this->___m_Bones;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_9 = L_8;
		if (L_9)
		{
			G_B11_0 = L_9;
			goto IL_0048;
		}
		G_B10_0 = L_9;
	}
	{
		return;
	}

IL_0048:
	{
		NullCheck(G_B11_0);
		VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E(G_B11_0, NULL);
	}

IL_004d:
	{
		return;
	}
}
// Method Definition Index: 58125
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 58106
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VertexBufferGenerator_1_get_VertexCount_m665635C5B082E9A8DB6D295AE372B3E50F34300A_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0;
		L_0 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return 0;
	}

IL_000a:
	{
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1;
		L_1 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_2;
		L_2 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		NullCheck(L_2);
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		NullCheck(L_1);
		int32_t L_4 = ((int32_t)il2cpp_codegen_subtract(L_3, 1));
		int32_t L_5 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
		return L_5;
	}
}
// Method Definition Index: 58107
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* VertexBufferGenerator_1_get_VertexIntervals_mCD3732FBC34E0839A0026E87644F191A1ED3E635_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = __this->___U3CVertexIntervalsU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 58108
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_set_VertexIntervals_m7AC6E1190422BD70D8762934C47A2B0976D8E2DE_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_value;
		__this->___U3CVertexIntervalsU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CVertexIntervalsU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 58109
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_GetVertexRange_m3AFEEAB2811FD808374740F9C7F98D612943568F_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_subMesh, int32_t* ___1_baseVertex, int32_t* ___2_vertexCount, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t* L_0 = ___1_baseVertex;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1;
		L_1 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_2 = ___0_subMesh;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		int32_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		*(L_0) = L_4;
		int32_t* L_5 = ___2_vertexCount;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6;
		L_6 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_7 = ___0_subMesh;
		NullCheck(L_6);
		int32_t L_8 = ((int32_t)il2cpp_codegen_add(L_7, 1));
		int32_t L_9 = (L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		int32_t* L_10 = ___1_baseVertex;
		int32_t L_11 = *(L_10);
		*(L_5) = ((int32_t)il2cpp_codegen_subtract(L_9, L_11));
		return;
	}
}
// Method Definition Index: 58110
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_TryGetBounds_m8134CEFC9C417F99DE86ACBFA959EE432AA59D61_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_subMesh, RuntimeObject* ___1_logger, Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3* ___2_bounds, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_0 = __this->___m_PositionAccessors;
		int32_t L_1 = ___0_subMesh;
		NullCheck(L_0);
		int32_t L_2 = L_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F L_4;
		L_4 = AccessorBase_TryGetBounds_mE38F5405047CC52A32D7E623A022F15BC041172F(L_3, NULL);
		V_0 = L_4;
		bool L_5;
		L_5 = Nullable_1_get_HasValue_m6578702C98214F7F52425ADD0766109D2BE9953B_inline((&V_0), NULL);
		if (!L_5)
		{
			goto IL_0026;
		}
	}
	{
		Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3* L_6 = ___2_bounds;
		Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3 L_7;
		L_7 = Nullable_1_get_Value_mC79E0A8A7D9E70CC7ABA0073EF626DE21DFADADB((&V_0), NULL);
		*(Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3*)L_6 = L_7;
		return (bool)1;
	}

IL_0026:
	{
		RuntimeObject* L_8 = ___1_logger;
		if (!L_8)
		{
			goto IL_004c;
		}
	}
	{
		RuntimeObject* L_9 = ___1_logger;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_10 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_11 = L_10;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_12 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_13 = ___0_subMesh;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_15);
		int32_t* L_16 = (int32_t*)(&L_15->___POSITION);
		String_t* L_17;
		L_17 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5(L_16, NULL);
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)L_17);
		NullCheck(L_9);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, L_9, ((int32_t)32), L_11);
	}

IL_004c:
	{
		Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3* L_18 = ___2_bounds;
		il2cpp_codegen_initobj(L_18, sizeof(Bounds_t367E830C64BBF235ED8C3B2F8CF6254FDCAD39C3));
		return (bool)0;
	}
}
// Method Definition Index: 58111
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1__ctor_mAC1FFF792356786D4BCB5505052FA96F9E5F0439_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_primitiveCount, RuntimeObject* ___1_buffers, RuntimeObject* ___2_logger, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = ___0_primitiveCount;
		RuntimeObject* L_1 = ___1_buffers;
		RuntimeObject* L_2 = ___2_logger;
		VertexBufferGeneratorBase__ctor_m8AE7BE0A5AA98BD3B83C9DF388451E5EA6DDCCF2((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this, L_0, L_1, L_2, NULL);
		return;
	}
}
// Method Definition Index: 58112
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_AddPrimitive_m2F198B7CEDF11A5B43F8532ACD68A3B1CC1CA29F_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_1 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_AttributeCount;
		V_0 = L_1;
		int32_t L_2 = V_0;
		((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_AttributeCount = ((int32_t)il2cpp_codegen_add(L_2, 1));
		int32_t L_3 = V_0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_4 = ___0_att;
		NullCheck(L_0);
		ArrayElementTypeCheck (L_0, L_4);
		(L_0)->SetAt(static_cast<il2cpp_array_size_t>(L_3), (Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*)L_4);
		return;
	}
}
// Method Definition Index: 58113
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Initialize_mDA45C6C60D3E9FAA469DB0B79505543A548BC24D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		V_0 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_0);
		int32_t L_1 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_0)->max_length),NULL));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_2 = (AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A*)(AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A*)SZArrayNew(AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A_il2cpp_TypeInfo_var, (uint32_t)L_1);
		__this->___m_PositionAccessors = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_PositionAccessors), (void*)L_2);
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_3 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_3);
		int32_t L_4 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_3)->max_length),NULL));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_5 = (Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*)SZArrayNew(Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_add(L_4, 1)));
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		VirtualActionInvoker1< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(11, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this, L_5);
		V_1 = 0;
		goto IL_006b;
	}

IL_002e:
	{
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_6;
		L_6 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_7 = V_1;
		int32_t L_8 = V_0;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (int32_t)L_8);
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_9 = __this->___m_PositionAccessors;
		int32_t L_10 = V_1;
		RuntimeObject* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_12 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_13 = V_1;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		NullCheck(L_15);
		int32_t L_16 = L_15->___POSITION;
		NullCheck(L_11);
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_17;
		L_17 = InterfaceFuncInvoker1< AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E*, int32_t >::Invoke(0, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_11, L_16);
		NullCheck(L_9);
		ArrayElementTypeCheck (L_9, L_17);
		(L_9)->SetAt(static_cast<il2cpp_array_size_t>(L_10), (AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E*)L_17);
		int32_t L_18 = V_0;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_19 = __this->___m_PositionAccessors;
		int32_t L_20 = V_1;
		NullCheck(L_19);
		int32_t L_21 = L_20;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_22 = (L_19)->GetAt(static_cast<il2cpp_array_size_t>(L_21));
		NullCheck(L_22);
		int32_t L_23 = L_22->___count;
		V_0 = ((int32_t)il2cpp_codegen_add(L_18, L_23));
		int32_t L_24 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_24, 1));
	}

IL_006b:
	{
		int32_t L_25 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_26 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_26);
		int32_t L_27 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_26)->max_length),NULL));
		if ((((int32_t)L_25) < ((int32_t)L_27)))
		{
			goto IL_002e;
		}
	}
	{
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_28;
		L_28 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_29 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_29);
		int32_t L_30 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_29)->max_length),NULL));
		int32_t L_31 = V_0;
		NullCheck(L_28);
		(L_28)->SetAt(static_cast<il2cpp_array_size_t>(L_30), (int32_t)L_31);
		return;
	}
}
// Method Definition Index: 58114
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Task_1_t824317F4B958F7512E8F7300511752937A6C6043* VertexBufferGenerator_1_CreateVertexBuffer_m39CEEAFB854A7B666318AF63AE491CFBAFDDE8EF_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_StaticInit);
	//<source_info:<no-source>:1>
	U3CCreateVertexBufferU3Ed__20_tCC7730169CE74300C548BDF2435F4F8FA2BCCA51 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		CHECKED_LOCAL_INIT(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_StaticInit,(AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA L_0;
		L_0 = AsyncTaskMethodBuilder_1_Create_mA86694527610A40A01A943B16F0ECDDD8F00982D(NULL);
		(&V_0)->___U3CU3Et__builder = L_0;
		Il2CppCodeGenWriteBarrier((void**)&((&(((&(&V_0)->___U3CU3Et__builder))->___m_coreState))->___m_stateMachine), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((&(((&(&V_0)->___U3CU3Et__builder))->___m_coreState))->___m_defaultContextAction), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&(((&(&V_0)->___U3CU3Et__builder))->___m_task), (void*)NULL);
		#endif
		(&V_0)->___U3CU3E4__this = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___U3CU3E4__this), (void*)__this);
		(&V_0)->___U3CU3E1__state = (-1);
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* L_1 = (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA*)(&(&V_0)->___U3CU3Et__builder);
		((  void (*) (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA*, U3CCreateVertexBufferU3Ed__20_tCC7730169CE74300C548BDF2435F4F8FA2BCCA51*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0)))(L_1, (&V_0), il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 0));
		AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA* L_2 = (AsyncTaskMethodBuilder_1_t651E7BA5C7209C40335555F361280911CF711AAA*)(&(&V_0)->___U3CU3Et__builder);
		Task_1_t824317F4B958F7512E8F7300511752937A6C6043* L_3;
		L_3 = AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943(L_2, AsyncTaskMethodBuilder_1_get_Task_m09169C120A259AF1F267F54C09A92B84D9832943_RuntimeMethod_var);
		return L_3;
	}
}
// Method Definition Index: 58115
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 VertexBufferGenerator_1_CreateVertexBufferHandle_m7C92F09537F1FDD27925454A2D45CBE1240A32D6_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	CHECKED_LOCAL(Type_t_StaticInit);
	CHECKED_LOCAL(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit);
	//<source_info:<no-source>:1>
	uint8_t* V_0 = NULL;
	int32_t V_1 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_2 = NULL;
	int32_t V_3 = 0;
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_4;
	memset((&V_4), 0, sizeof(V_4));
	int32_t V_5 = 0;
	int32_t V_6 = 0;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* V_7 = NULL;
	int32_t V_8 = 0;
	int32_t V_9 = 0;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_10 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_11;
	memset((&V_11), 0, sizeof(V_11));
	RuntimeObject* G_B4_0 = NULL;
	RuntimeObject* G_B3_0 = NULL;
	VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* G_B21_0 = NULL;
	VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* G_B20_0 = NULL;
	int32_t G_B22_0 = 0;
	VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* G_B22_1 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B28_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B26_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B27_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B30_0 = NULL;
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* G_B29_0 = NULL;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 G_B56_0;
	memset((&G_B56_0), 0, sizeof(G_B56_0));
	{
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_0;
		L_0 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_1;
		memset((&L_1), 0, sizeof(L_1));
		NativeArray_1__ctor_m788DE0F85C4051DDF092DDF96484DE655ACFB6F1((&L_1), L_0, 4, 1, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 1));
		__this->___m_Data = L_1;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_2 = __this->___m_Data;
		void* L_3;
		L_3 = ((  void* (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 2)))(L_2, NULL);
		V_0 = (uint8_t*)L_3;
		V_1 = 0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_4);
		int32_t L_5 = 0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_6 = (L_4)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		V_2 = L_6;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_7 = V_2;
		NullCheck(L_7);
		int32_t L_8;
		L_8 = Attributes_GetTexCoordsCount_m6C89F48FD7741F8F2E532F3C9AC74B0C17B094E7(L_7, NULL);
		V_3 = L_8;
		int32_t L_9 = V_3;
		if ((((int32_t)L_9) <= ((int32_t)0)))
		{
			goto IL_0148;
		}
	}
	{
		int32_t L_10 = V_3;
		if ((((int32_t)L_10) <= ((int32_t)8)))
		{
			goto IL_0056;
		}
	}
	{
		RuntimeObject* L_11 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		RuntimeObject* L_12 = L_11;
		if (L_12)
		{
			G_B4_0 = L_12;
			goto IL_0048;
		}
		G_B3_0 = L_12;
	}
	{
		goto IL_0054;
	}

IL_0048:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_13;
		L_13 = Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_inline(Array_Empty_TisString_t_m9832B70DF2B936246FE60F75D3D12CB946C39D16_RuntimeMethod_var);
		NullCheck(G_B4_0);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(1, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B4_0, ((int32_t)51), L_13);
	}

IL_0054:
	{
		V_3 = 8;
	}

IL_0056:
	{
		int32_t L_14 = V_1;
		int32_t L_15 = V_3;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_16 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_16);
		int32_t L_17 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_16)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_14, ((int32_t)il2cpp_codegen_multiply(L_15, L_17))));
		int32_t L_18 = V_3;
		switch (((int32_t)il2cpp_codegen_subtract(L_18, 1)))
		{
			case 0:
			{
				goto IL_008c;
			}
			case 1:
			{
				goto IL_00a5;
			}
			case 2:
			{
				goto IL_00be;
			}
			case 3:
			{
				goto IL_00d4;
			}
			case 4:
			{
				goto IL_00ea;
			}
			case 5:
			{
				goto IL_0100;
			}
			case 6:
			{
				goto IL_0116;
			}
		}
	}
	{
		goto IL_012c;
	}

IL_008c:
	{
		int32_t L_19 = V_3;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_20;
		L_20 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_21 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482* L_22 = (VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tC3BDF50CB5E32BFCCFB7064627B3D5DC83393482_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m6A5226232A2E0E63F0D7879B7AA891933D0DC5D0(L_22, L_19, L_20, L_21, NULL);
		V_7 = L_22;
		goto IL_0140;
	}

IL_00a5:
	{
		int32_t L_23 = V_3;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_24;
		L_24 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_25 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23* L_26 = (VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t6CBD8211FE92E60197C0EF941C957A983526EB23_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m31ADF0E3C02E555FE593A2591DFE81D9465279BE(L_26, L_23, L_24, L_25, NULL);
		V_7 = L_26;
		goto IL_0140;
	}

IL_00be:
	{
		int32_t L_27 = V_3;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_28;
		L_28 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_29 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5* L_30 = (VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t3B99BD487AB6873EFDC1FAA5D7DB0ABBE0DC7AE5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m0381D1FE2C1AF708958B3C3B22C7C1DA589044D1(L_30, L_27, L_28, L_29, NULL);
		V_7 = L_30;
		goto IL_0140;
	}

IL_00d4:
	{
		int32_t L_31 = V_3;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_32;
		L_32 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_33 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5* L_34 = (VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tA1BA5DAC582DFF8ABF0B7BBB327779457CAFECB5_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m77CF6C47CF7BA9F6BFA26038C2103388C546B4A9(L_34, L_31, L_32, L_33, NULL);
		V_7 = L_34;
		goto IL_0140;
	}

IL_00ea:
	{
		int32_t L_35 = V_3;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_36;
		L_36 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_37 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD* L_38 = (VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t48017CD75C653014CC31AB22EADFE5549D8170AD_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mE90EFC019B42B5E0CD297E219EAF206835110333(L_38, L_35, L_36, L_37, NULL);
		V_7 = L_38;
		goto IL_0140;
	}

IL_0100:
	{
		int32_t L_39 = V_3;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_40;
		L_40 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_41 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229* L_42 = (VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_t2D0F14D7A7B4C89C7A20F54687020C3289812229_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_m405883C02E7D9F9F23C1CFF12BBE9594946458F5(L_42, L_39, L_40, L_41, NULL);
		V_7 = L_42;
		goto IL_0140;
	}

IL_0116:
	{
		int32_t L_43 = V_3;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_44;
		L_44 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_45 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399* L_46 = (VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tBD136D046A119A6622512E880345702174DDD399_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC612FB33351D1DFBE038C6C5A05476F3F3FACA19(L_46, L_43, L_44, L_45, NULL);
		V_7 = L_46;
		goto IL_0140;
	}

IL_012c:
	{
		int32_t L_47 = V_3;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_48;
		L_48 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_49 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595* L_50 = (VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595*)il2cpp_codegen_object_new(VertexBufferTexCoords_1_tD9F54B25F60E12C291EE1B1C97A73B415901F595_il2cpp_TypeInfo_var);
		VertexBufferTexCoords_1__ctor_mC7062217B4C04E90EDBC5B555752987C772F4016(L_50, L_47, L_48, L_49, NULL);
		V_7 = L_50;
	}

IL_0140:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_51 = V_7;
		__this->___m_TexCoords = L_51;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_TexCoords), (void*)L_51);
	}

IL_0148:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_52 = V_2;
		NullCheck(L_52);
		int32_t L_53 = L_52->___COLOR_0;
		__this->___m_HasColors = (bool)((((int32_t)((((int32_t)L_53) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_54 = __this->___m_HasColors;
		if (!L_54)
		{
			goto IL_0184;
		}
	}
	{
		int32_t L_55 = V_1;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_56 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_56);
		int32_t L_57 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_56)->max_length),NULL));
		V_1 = ((int32_t)il2cpp_codegen_add(L_55, L_57));
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_58;
		L_58 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_59 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_60 = (VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA*)il2cpp_codegen_object_new(VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA_il2cpp_TypeInfo_var);
		VertexBufferColors__ctor_m69DC0D4F4EB90EF822B6B68A54E9BDD61942472C(L_60, L_58, L_59, NULL);
		__this->___m_Colors = L_60;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Colors), (void*)L_60);
	}

IL_0184:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_61 = V_2;
		NullCheck(L_61);
		int32_t L_62 = L_61->___WEIGHTS_0;
		if ((((int32_t)L_62) < ((int32_t)0)))
		{
			G_B21_0 = __this;
			goto IL_019c;
		}
		G_B20_0 = __this;
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_63 = V_2;
		NullCheck(L_63);
		int32_t L_64 = L_63->___JOINTS_0;
		G_B22_0 = ((((int32_t)((((int32_t)L_64) < ((int32_t)0))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		G_B22_1 = G_B20_0;
		goto IL_019d;
	}

IL_019c:
	{
		G_B22_0 = 0;
		G_B22_1 = G_B21_0;
	}

IL_019d:
	{
		NullCheck(G_B22_1);
		G_B22_1->___m_HasBones = (bool)G_B22_0;
		bool L_65 = __this->___m_HasBones;
		if (!L_65)
		{
			goto IL_01c5;
		}
	}
	{
		int32_t L_66 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_66, 1));
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_67;
		L_67 = VirtualFuncInvoker0< int32_t >::Invoke(9, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		RuntimeObject* L_68 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_69 = (VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94*)il2cpp_codegen_object_new(VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94_il2cpp_TypeInfo_var);
		VertexBufferBones__ctor_m72D3CB3A42C2DAF5401A14BAA910AB2E2C2E616D(L_69, L_67, L_68, NULL);
		__this->___m_Bones = L_69;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_Bones), (void*)L_69);
	}

IL_01c5:
	{
		V_8 = 0;
		goto IL_0252;
	}

IL_01cd:
	{
		int32_t L_70 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_70, 1));
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_71 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_72 = V_8;
		NullCheck(L_71);
		int32_t L_73 = L_72;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_74 = (L_71)->GetAt(static_cast<il2cpp_array_size_t>(L_73));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_75 = __this->___m_PositionAccessors;
		int32_t L_76 = V_8;
		NullCheck(L_75);
		int32_t L_77 = L_76;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_78 = (L_75)->GetAt(static_cast<il2cpp_array_size_t>(L_77));
		NullCheck(L_78);
		bool L_79;
		L_79 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_78, NULL);
		if (!L_79)
		{
			G_B28_0 = L_74;
			goto IL_01ff;
		}
		G_B26_0 = L_74;
	}
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_80 = __this->___m_PositionAccessors;
		int32_t L_81 = V_8;
		NullCheck(L_80);
		int32_t L_82 = L_81;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_83 = (L_80)->GetAt(static_cast<il2cpp_array_size_t>(L_82));
		NullCheck(L_83);
		int32_t L_84 = L_83->___bufferView;
		if ((((int32_t)L_84) < ((int32_t)0)))
		{
			G_B28_0 = G_B26_0;
			goto IL_01ff;
		}
		G_B27_0 = G_B26_0;
	}
	{
		int32_t L_85 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_85, 1));
		G_B28_0 = G_B27_0;
	}

IL_01ff:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_86 = G_B28_0;
		NullCheck(L_86);
		int32_t L_87 = L_86->___NORMAL;
		if ((((int32_t)L_87) < ((int32_t)0)))
		{
			G_B30_0 = L_86;
			goto IL_0213;
		}
		G_B29_0 = L_86;
	}
	{
		int32_t L_88 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_88, 1));
		__this->___m_HasNormals = (bool)1;
		G_B30_0 = G_B29_0;
	}

IL_0213:
	{
		bool L_89 = __this->___m_HasNormals;
		bool L_90 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateNormals;
		__this->___m_HasNormals = (bool)((int32_t)((int32_t)L_89|(int32_t)L_90));
		NullCheck(G_B30_0);
		int32_t L_91 = G_B30_0->___TANGENT;
		if ((((int32_t)L_91) < ((int32_t)0)))
		{
			goto IL_0239;
		}
	}
	{
		int32_t L_92 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_92, 1));
		__this->___m_HasTangents = (bool)1;
	}

IL_0239:
	{
		bool L_93 = __this->___m_HasTangents;
		bool L_94 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___calculateTangents;
		__this->___m_HasTangents = (bool)((int32_t)((int32_t)L_93|(int32_t)L_94));
		int32_t L_95 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_95, 1));
	}

IL_0252:
	{
		int32_t L_96 = V_8;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_97 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_97);
		int32_t L_98 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_97)->max_length),NULL));
		if ((((int32_t)L_96) < ((int32_t)L_98)))
		{
			goto IL_01cd;
		}
	}
	{
		int32_t L_99 = V_1;
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_4), L_99, 4, 1, NULL);
		V_5 = 0;
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_100 = { reinterpret_cast<intptr_t> (il2cpp_rgctx_type(il2cpp_codegen_method_rgctx(method), 3)) };
		CHECKED_LOCAL_INIT(Type_t_StaticInit,(Type_t_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		Type_t* L_101;
		L_101 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_100, NULL);
		CHECKED_LOCAL_INIT(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_StaticInit,(Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var),il2cpp_codegen_runtime_class_init_inline);
		int32_t L_102;
		L_102 = Marshal_SizeOf_mED64846722033D6F60C2973CA604B7C2D7D4A1B7(L_101, NULL);
		V_6 = L_102;
		V_9 = 0;
		goto IL_0340;
	}

IL_0287:
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_103 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_104 = V_9;
		NullCheck(L_103);
		int32_t L_105 = L_104;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_106 = (L_103)->GetAt(static_cast<il2cpp_array_size_t>(L_105));
		V_10 = L_106;
		int32_t L_107 = V_9;
		uint8_t* L_108 = V_0;
		int32_t L_109 = V_6;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_110 = V_4;
		bool L_111;
		L_111 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, int32_t, uint8_t*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 5)))(__this, L_107, L_108, L_109, L_110, (&V_5), NULL);
		if (L_111)
		{
			goto IL_02ae;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_112 = V_11;
		return L_112;
	}

IL_02ae:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_113 = V_10;
		NullCheck(L_113);
		int32_t L_114 = L_113->___NORMAL;
		if ((((int32_t)L_114) < ((int32_t)0)))
		{
			goto IL_02d6;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_115 = V_10;
		uint8_t* L_116 = V_0;
		int32_t L_117 = V_6;
		int32_t L_118 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_119 = V_4;
		bool L_120;
		L_120 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 6)))(__this, L_115, L_116, L_117, L_118, L_119, (&V_5), NULL);
		if (L_120)
		{
			goto IL_02d6;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_121 = V_11;
		return L_121;
	}

IL_02d6:
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_122 = V_10;
		NullCheck(L_122);
		int32_t L_123 = L_122->___TANGENT;
		if ((((int32_t)L_123) < ((int32_t)0)))
		{
			goto IL_02fe;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_124 = V_10;
		uint8_t* L_125 = V_0;
		int32_t L_126 = V_6;
		int32_t L_127 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_128 = V_4;
		bool L_129;
		L_129 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, uint8_t*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 7)))(__this, L_124, L_125, L_126, L_127, L_128, (&V_5), NULL);
		if (L_129)
		{
			goto IL_02fe;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_130 = V_11;
		return L_130;
	}

IL_02fe:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_131 = __this->___m_TexCoords;
		if (!L_131)
		{
			goto IL_0317;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_132 = V_10;
		int32_t L_133 = V_3;
		int32_t L_134 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_135 = V_4;
		int32_t L_136 = V_5;
		int32_t L_137;
		L_137 = ((  int32_t (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 8)))(__this, L_132, L_133, L_134, L_135, L_136, NULL);
		V_5 = L_137;
	}

IL_0317:
	{
		bool L_138 = __this->___m_HasColors;
		if (!L_138)
		{
			goto IL_033a;
		}
	}
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_139 = V_10;
		int32_t L_140 = V_9;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_141 = V_4;
		bool L_142;
		L_142 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B*, int32_t, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, int32_t*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 9)))(__this, L_139, L_140, L_141, (&V_5), NULL);
		if (L_142)
		{
			goto IL_033a;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_143 = V_11;
		return L_143;
	}

IL_033a:
	{
		int32_t L_144 = V_9;
		V_9 = ((int32_t)il2cpp_codegen_add(L_144, 1));
	}

IL_0340:
	{
		int32_t L_145 = V_9;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_146 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		NullCheck(L_146);
		int32_t L_147 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_146)->max_length),NULL));
		if ((((int32_t)L_145) < ((int32_t)L_147)))
		{
			goto IL_0287;
		}
	}
	{
		bool L_148 = __this->___m_HasBones;
		if (!L_148)
		{
			goto IL_037a;
		}
	}
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_149 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Attributes;
		int32_t L_150 = V_5;
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_151;
		L_151 = NativeArray_1_GetSubArray_mA9C8FA837D0A861E42C28E31C02AF86688C0801E((&V_4), L_150, 1, NULL);
		bool L_152;
		L_152 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322*, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10)))(__this, L_149, L_151, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 10));
		if (L_152)
		{
			goto IL_037a;
		}
	}
	{
		il2cpp_codegen_initobj((&V_11), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_153 = V_11;
		return L_153;
	}

IL_037a:
	{
		int32_t L_154 = V_1;
		if ((((int32_t)L_154) > ((int32_t)1)))
		{
			goto IL_0388;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_155;
		L_155 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_4))->___m_Buffer, 0);
		G_B56_0 = L_155;
		goto IL_038f;
	}

IL_0388:
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_156 = V_4;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_157;
		L_157 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_156, NULL);
		G_B56_0 = L_157;
	}

IL_038f:
	{
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_4), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_158;
		memset((&L_158), 0, sizeof(L_158));
		Nullable_1__ctor_mB41B318820A405D727A0192457EC35740E6B7526((&L_158), G_B56_0, NULL);
		return L_158;
	}
}
// Method Definition Index: 58116
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_SchedulePositionsJobs_m9F602C8636577BFDFEBF4169A7CF6F0636BBD79A_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_i, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t* ___4_handleIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_0;
	memset((&V_0), 0, sizeof(V_0));
	void* V_1 = NULL;
	void* V_2 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_3;
	memset((&V_3), 0, sizeof(V_3));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489));
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_0 = __this->___m_PositionAccessors;
		int32_t L_1 = ___0_i;
		NullCheck(L_0);
		int32_t L_2 = L_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		NullCheck(L_3);
		int32_t L_4 = L_3->___bufferView;
		if ((((int32_t)L_4) < ((int32_t)0)))
		{
			goto IL_0047;
		}
	}
	{
		RuntimeObject* L_5 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_6 = __this->___m_PositionAccessors;
		int32_t L_7 = ___0_i;
		NullCheck(L_6);
		int32_t L_8 = L_7;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_9 = (L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		uint8_t* L_10 = ___1_vDataPtr;
		int32_t L_11 = ___2_outputByteStride;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_12;
		L_12 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_13 = ___0_i;
		NullCheck(L_12);
		int32_t L_14 = L_13;
		int32_t L_15 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
		int32_t L_16 = ___2_outputByteStride;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_17 = __this->___m_PositionAccessors;
		int32_t L_18 = ___0_i;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		NullCheck(L_20);
		bool L_21 = L_20->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_22;
		L_22 = VertexBufferGeneratorBase_GetVector3Job_m927290C4C47D6AC7254AE09C0DA34D29321E7042(L_5, L_9, (float3_t7600B73F092B37F484B12910A5269F30C778D31E*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_10, ((int32_t)il2cpp_codegen_multiply(L_11, L_15)))), L_16, L_21, (bool)0, NULL);
		V_0 = L_22;
	}

IL_0047:
	{
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_23 = __this->___m_PositionAccessors;
		int32_t L_24 = ___0_i;
		NullCheck(L_23);
		int32_t L_25 = L_24;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_26 = (L_23)->GetAt(static_cast<il2cpp_array_size_t>(L_25));
		NullCheck(L_26);
		bool L_27;
		L_27 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_26, NULL);
		if (!L_27)
		{
			goto IL_0117;
		}
	}
	{
		RuntimeObject* L_28 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_29 = __this->___m_PositionAccessors;
		int32_t L_30 = ___0_i;
		NullCheck(L_29);
		int32_t L_31 = L_30;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_32 = (L_29)->GetAt(static_cast<il2cpp_array_size_t>(L_31));
		NullCheck(L_32);
		AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* L_33;
		L_33 = VirtualFuncInvoker0< AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* >::Invoke(4, L_32);
		NullCheck(L_33);
		AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6* L_34;
		L_34 = VirtualFuncInvoker0< AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6* >::Invoke(4, L_33);
		NullCheck(L_28);
		InterfaceActionInvoker2< AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6*, void** >::Invoke(2, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_28, L_34, (&V_1));
		RuntimeObject* L_35 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_36 = __this->___m_PositionAccessors;
		int32_t L_37 = ___0_i;
		NullCheck(L_36);
		int32_t L_38 = L_37;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_39 = (L_36)->GetAt(static_cast<il2cpp_array_size_t>(L_38));
		NullCheck(L_39);
		AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* L_40;
		L_40 = VirtualFuncInvoker0< AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* >::Invoke(4, L_39);
		NullCheck(L_40);
		AccessorSparseValues_t44A45125EF7E14021915DACA49F5CCECF5948071* L_41;
		L_41 = VirtualFuncInvoker0< AccessorSparseValues_t44A45125EF7E14021915DACA49F5CCECF5948071* >::Invoke(5, L_40);
		NullCheck(L_35);
		InterfaceActionInvoker2< AccessorSparseValues_t44A45125EF7E14021915DACA49F5CCECF5948071*, void** >::Invoke(3, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_35, L_41, (&V_2));
		void* L_42 = V_1;
		void* L_43 = V_2;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_44 = __this->___m_PositionAccessors;
		int32_t L_45 = ___0_i;
		NullCheck(L_44);
		int32_t L_46 = L_45;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_47 = (L_44)->GetAt(static_cast<il2cpp_array_size_t>(L_46));
		NullCheck(L_47);
		AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* L_48;
		L_48 = VirtualFuncInvoker0< AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* >::Invoke(4, L_47);
		NullCheck(L_48);
		int32_t L_49 = L_48->___count;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_50 = __this->___m_PositionAccessors;
		int32_t L_51 = ___0_i;
		NullCheck(L_50);
		int32_t L_52 = L_51;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_53 = (L_50)->GetAt(static_cast<il2cpp_array_size_t>(L_52));
		NullCheck(L_53);
		AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* L_54;
		L_54 = VirtualFuncInvoker0< AccessorSparseBase_t86D7B632EF0A39D188BCD347D1BE5299877767DD* >::Invoke(4, L_53);
		NullCheck(L_54);
		AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6* L_55;
		L_55 = VirtualFuncInvoker0< AccessorSparseIndices_tBF8FD2DBF949DD267D4D541F1CECADDB71501EC6* >::Invoke(4, L_54);
		NullCheck(L_55);
		int32_t L_56 = L_55->___componentType;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_57 = __this->___m_PositionAccessors;
		int32_t L_58 = ___0_i;
		NullCheck(L_57);
		int32_t L_59 = L_58;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_60 = (L_57)->GetAt(static_cast<il2cpp_array_size_t>(L_59));
		NullCheck(L_60);
		int32_t L_61 = L_60->___componentType;
		uint8_t* L_62 = ___1_vDataPtr;
		int32_t L_63 = ___2_outputByteStride;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_64;
		L_64 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_65 = ___0_i;
		NullCheck(L_64);
		int32_t L_66 = L_65;
		int32_t L_67 = (L_64)->GetAt(static_cast<il2cpp_array_size_t>(L_66));
		int32_t L_68 = ___2_outputByteStride;
		AccessorBaseU5BU5D_tBB228DEBD66B346B0EBFA26DC83871757CEE3D9A* L_69 = __this->___m_PositionAccessors;
		int32_t L_70 = ___0_i;
		NullCheck(L_69);
		int32_t L_71 = L_70;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_72 = (L_69)->GetAt(static_cast<il2cpp_array_size_t>(L_71));
		NullCheck(L_72);
		bool L_73 = L_72->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_74;
		L_74 = VertexBufferGeneratorBase_GetVector3SparseJob_m40E689FD8B2D5E53344AA7C5F2F77B8025127D3B(L_42, L_43, L_49, L_56, L_61, (float3_t7600B73F092B37F484B12910A5269F30C778D31E*)((uint8_t*)il2cpp_codegen_add((intptr_t)L_62, ((int32_t)il2cpp_codegen_multiply(L_63, L_67)))), L_68, (&V_0), L_73, NULL);
		V_3 = L_74;
		bool L_75;
		L_75 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_3), NULL);
		if (!L_75)
		{
			goto IL_0115;
		}
	}
	{
		int32_t* L_76 = ___4_handleIndex;
		int32_t L_77 = *(L_76);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_78;
		L_78 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_3), NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___3_handles))->___m_Buffer, L_77, (L_78));
		int32_t* L_79 = ___4_handleIndex;
		int32_t* L_80 = ___4_handleIndex;
		int32_t L_81 = *(L_80);
		*(L_79) = ((int32_t)il2cpp_codegen_add(L_81, 1));
		goto IL_0117;
	}

IL_0115:
	{
		return (bool)0;
	}

IL_0117:
	{
		bool L_82;
		L_82 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_0), NULL);
		if (!L_82)
		{
			goto IL_013b;
		}
	}
	{
		int32_t* L_83 = ___4_handleIndex;
		int32_t L_84 = *(L_83);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_85;
		L_85 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_0), NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___3_handles))->___m_Buffer, L_84, (L_85));
		int32_t* L_86 = ___4_handleIndex;
		int32_t* L_87 = ___4_handleIndex;
		int32_t L_88 = *(L_87);
		*(L_86) = ((int32_t)il2cpp_codegen_add(L_88, 1));
		goto IL_013d;
	}

IL_013b:
	{
		return (bool)0;
	}

IL_013d:
	{
		return (bool)1;
	}
}
// Method Definition Index: 58117
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleNormalsJobs_m22053E3C11AC564CC9359CAA58014657FD80709D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBF92C939C85D8888B68A1C0E975839B22C2F1CA0);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_0 = NULL;
	void* V_1 = NULL;
	int32_t V_2 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_3;
	memset((&V_3), 0, sizeof(V_3));
	RuntimeObject* G_B3_0 = NULL;
	RuntimeObject* G_B2_0 = NULL;
	{
		RuntimeObject* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_1 = ___0_att;
		NullCheck(L_1);
		int32_t L_2 = L_1->___NORMAL;
		NullCheck(L_0);
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(1, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_0, L_2, (&V_0), (&V_1), (&V_2));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_3 = V_0;
		NullCheck(L_3);
		bool L_4;
		L_4 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_3, NULL);
		if (!L_4)
		{
			goto IL_0040;
		}
	}
	{
		RuntimeObject* L_5 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		RuntimeObject* L_6 = L_5;
		if (L_6)
		{
			G_B3_0 = L_6;
			goto IL_002b;
		}
		G_B2_0 = L_6;
	}
	{
		goto IL_0040;
	}

IL_002b:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_7 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_8 = L_7;
		NullCheck(L_8);
		(L_8)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteralBF92C939C85D8888B68A1C0E975839B22C2F1CA0);
		NullCheck(G_B3_0);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B3_0, ((int32_t)42), L_8);
	}

IL_0040:
	{
		RuntimeObject* L_9 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_0;
		uint8_t* L_11 = ___1_vDataPtr;
		int32_t L_12 = ___2_outputByteStride;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_13;
		L_13 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_14 = ___3_i;
		NullCheck(L_13);
		int32_t L_15 = L_14;
		int32_t L_16 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_15));
		int32_t L_17 = ___2_outputByteStride;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_18 = V_0;
		NullCheck(L_18);
		bool L_19 = L_18->___normalized;
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_20;
		L_20 = VertexBufferGeneratorBase_GetVector3Job_m927290C4C47D6AC7254AE09C0DA34D29321E7042(L_9, L_10, (float3_t7600B73F092B37F484B12910A5269F30C778D31E*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_11, ((int32_t)il2cpp_codegen_multiply(L_12, L_16)))), ((int32_t)12))), L_17, L_19, (bool)1, NULL);
		V_3 = L_20;
		bool L_21;
		L_21 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_3), NULL);
		if (!L_21)
		{
			goto IL_0089;
		}
	}
	{
		int32_t* L_22 = ___5_handleIndex;
		int32_t L_23 = *(L_22);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_24;
		L_24 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_3), NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___4_handles))->___m_Buffer, L_23, (L_24));
		int32_t* L_25 = ___5_handleIndex;
		int32_t* L_26 = ___5_handleIndex;
		int32_t L_27 = *(L_26);
		*(L_25) = ((int32_t)il2cpp_codegen_add(L_27, 1));
		goto IL_008b;
	}

IL_0089:
	{
		return (bool)0;
	}

IL_008b:
	{
		return (bool)1;
	}
}
// Method Definition Index: 58118
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleTangentsJobs_mF7C7568119B29BC7075F80000530325A0CF0802D_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, uint8_t* ___1_vDataPtr, int32_t ___2_outputByteStride, int32_t ___3_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___4_handles, int32_t* ___5_handleIndex, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral695F5F858DF14780BC5525F0AA16CE70EB9C45E8);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* V_0 = NULL;
	void* V_1 = NULL;
	int32_t V_2 = 0;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_3;
	memset((&V_3), 0, sizeof(V_3));
	RuntimeObject* G_B3_0 = NULL;
	RuntimeObject* G_B2_0 = NULL;
	{
		RuntimeObject* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_1 = ___0_att;
		NullCheck(L_1);
		int32_t L_2 = L_1->___TANGENT;
		NullCheck(L_0);
		InterfaceActionInvoker4< int32_t, AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E**, void**, int32_t* >::Invoke(1, IGltfBuffers_t00BA2FBEDB51454535E849F99340C2DDB9D60E47_il2cpp_TypeInfo_var, L_0, L_2, (&V_0), (&V_1), (&V_2));
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_3 = V_0;
		NullCheck(L_3);
		bool L_4;
		L_4 = AccessorBase_get_IsSparse_m5F3AE9ABE368BAA1C86E4D5BC6FC651191E5BA17(L_3, NULL);
		if (!L_4)
		{
			goto IL_0040;
		}
	}
	{
		RuntimeObject* L_5 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Logger;
		RuntimeObject* L_6 = L_5;
		if (L_6)
		{
			G_B3_0 = L_6;
			goto IL_002b;
		}
		G_B2_0 = L_6;
	}
	{
		goto IL_0040;
	}

IL_002b:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_7 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)1);
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_8 = L_7;
		NullCheck(L_8);
		(L_8)->SetAt(static_cast<il2cpp_array_size_t>(0), (String_t*)_stringLiteral695F5F858DF14780BC5525F0AA16CE70EB9C45E8);
		NullCheck(G_B3_0);
		InterfaceActionInvoker2< uint32_t, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* >::Invoke(0, ICodeLogger_t0AB041B7272F7E2D664B3B8BA707F69E7E8C235A_il2cpp_TypeInfo_var, G_B3_0, ((int32_t)42), L_8);
	}

IL_0040:
	{
		void* L_9 = V_1;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_10 = V_0;
		NullCheck(L_10);
		int32_t L_11 = L_10->___count;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_12 = V_0;
		NullCheck(L_12);
		int32_t L_13 = L_12->___componentType;
		int32_t L_14 = V_2;
		uint8_t* L_15 = ___1_vDataPtr;
		int32_t L_16 = ___2_outputByteStride;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_17;
		L_17 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_18 = ___3_i;
		NullCheck(L_17);
		int32_t L_19 = L_18;
		int32_t L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
		int32_t L_21 = ___2_outputByteStride;
		AccessorBase_tF25205852B7D4F67A7F42894B89791CB19BBFA9E* L_22 = V_0;
		NullCheck(L_22);
		bool L_23 = L_22->___normalized;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_24;
		L_24 = VertexBufferGeneratorBase_GetTangentsJob_mA4F2AA421F08AF0793274A4BEB952FB29D96C3C3((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this, L_9, L_11, L_13, L_14, (float4_t545A994996126766890C1F28B43EA823F2410190*)((uint8_t*)il2cpp_codegen_add((intptr_t)((uint8_t*)il2cpp_codegen_add((intptr_t)L_15, ((int32_t)il2cpp_codegen_multiply(L_16, L_20)))), ((int32_t)24))), L_21, L_23, NULL);
		V_3 = L_24;
		bool L_25;
		L_25 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_3), NULL);
		if (!L_25)
		{
			goto IL_0090;
		}
	}
	{
		int32_t* L_26 = ___5_handleIndex;
		int32_t L_27 = *(L_26);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_28;
		L_28 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_3), NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___4_handles))->___m_Buffer, L_27, (L_28));
		int32_t* L_29 = ___5_handleIndex;
		int32_t* L_30 = ___5_handleIndex;
		int32_t L_31 = *(L_30);
		*(L_29) = ((int32_t)il2cpp_codegen_add(L_31, 1));
		goto IL_0092;
	}

IL_0090:
	{
		return (bool)0;
	}

IL_0092:
	{
		return (bool)1;
	}
}
// Method Definition Index: 58119
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t VertexBufferGenerator_1_ScheduleTexCoordJobs_m85AA5C7776DD570FBC82C0AF28A173D65A6AD791_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_uvSetCount, int32_t ___2_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___3_handles, int32_t ___4_handleIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* V_0 = NULL;
	bool V_1 = false;
	{
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_0 = ___0_att;
		NullCheck(L_0);
		bool L_1;
		L_1 = Attributes_TryGetAllUVAccessors_m30F2F2BCFC23CC3184624E1B24885C7C1D3AD90E(L_0, (&V_0), (&V_1), NULL);
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_2 = __this->___m_TexCoords;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3;
		L_3 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_4 = ___2_i;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		int32_t L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_7 = V_0;
		int32_t L_8 = ___4_handleIndex;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_9 = V_0;
		NullCheck(L_9);
		int32_t L_10 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_9)->max_length),NULL));
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_11;
		L_11 = NativeArray_1_GetSubArray_mA9C8FA837D0A861E42C28E31C02AF86688C0801E((&___3_handles), L_8, L_10, NULL);
		RuntimeObject* L_12 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		NullCheck(L_2);
		bool L_13;
		L_13 = VirtualFuncInvoker4< bool, int32_t, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C*, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0, RuntimeObject* >::Invoke(5, L_2, L_6, L_7, L_11, L_12);
		int32_t L_14 = ___4_handleIndex;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_15 = V_0;
		NullCheck(L_15);
		int32_t L_16 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_15)->max_length),NULL));
		___4_handleIndex = ((int32_t)il2cpp_codegen_add(L_14, L_16));
		int32_t L_17 = ___4_handleIndex;
		return L_17;
	}
}
// Method Definition Index: 58120
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleColorsJobs_mB2527AC43D002D2D41C27F86E2FDEC76126EF0F1_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* ___0_att, int32_t ___1_i, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___2_handles, int32_t* ___3_handleIndex, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_0 = __this->___m_Colors;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_1 = ___0_att;
		NullCheck(L_1);
		int32_t L_2 = L_1->___COLOR_0;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3;
		L_3 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_4 = ___1_i;
		NullCheck(L_3);
		int32_t L_5 = L_4;
		int32_t L_6 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_5));
		int32_t* L_7 = ___3_handleIndex;
		int32_t L_8 = *(L_7);
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_9;
		L_9 = NativeArray_1_GetSubArray_mA9C8FA837D0A861E42C28E31C02AF86688C0801E((&___2_handles), L_8, 1, NULL);
		RuntimeObject* L_10 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		NullCheck(L_0);
		bool L_11;
		L_11 = VertexBufferColors_ScheduleVertexColorJob_m04DB2B7BE59977BB358A9AF4EAC4B501ACEB3CF8(L_0, L_2, L_6, L_9, L_10, NULL);
		if (L_11)
		{
			goto IL_002e;
		}
	}
	{
		return (bool)0;
	}

IL_002e:
	{
		int32_t* L_12 = ___3_handleIndex;
		int32_t* L_13 = ___3_handleIndex;
		int32_t L_14 = *(L_13);
		*(L_12) = ((int32_t)il2cpp_codegen_add(L_14, 1));
		return (bool)1;
	}
}
// Method Definition Index: 58121
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_ScheduleVertexBonesJobs_mEA397EA120DAD23DCFE4C47F594623AA9EC7DDA7_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* ___0_attributes, NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 ___1_handles, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684 V_0;
	memset((&V_0), 0, sizeof(V_0));
	NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_3;
	memset((&V_3), 0, sizeof(V_3));
	JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 V_4;
	memset((&V_4), 0, sizeof(V_4));
	{
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_0 = ___0_attributes;
		(&V_0)->___attributes = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___attributes), (void*)L_0);
		(&V_0)->___U3CU3E4__this = __this;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___U3CU3E4__this), (void*)__this);
		U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684 L_1 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_2 = L_1.___attributes;
		NullCheck(L_2);
		int32_t L_3 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_2)->max_length),NULL));
		if ((((int32_t)L_3) <= ((int32_t)1)))
		{
			goto IL_006e;
		}
	}
	{
		U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684 L_4 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_5 = L_4.___attributes;
		NullCheck(L_5);
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_5)->max_length),NULL));
		NativeArray_1__ctor_mAB9F77B2DF6AEE780DF94369A6332C6C7B9A238E((&V_1), L_6, 2, 1, NULL);
		V_2 = 0;
		goto IL_004c;
	}

IL_0030:
	{
		int32_t L_7 = V_2;
		bool L_8;
		L_8 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, int32_t, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(__this, L_7, (&V_3), (&V_0), NULL);
		if (L_8)
		{
			goto IL_003f;
		}
	}
	{
		return (bool)0;
	}

IL_003f:
	{
		int32_t L_9 = V_2;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_10 = V_3;
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&V_1))->___m_Buffer, L_9, (L_10));
		int32_t L_11 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_004c:
	{
		int32_t L_12 = V_2;
		U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684 L_13 = V_0;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_14 = L_13.___attributes;
		NullCheck(L_14);
		int32_t L_15 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>((((RuntimeArray*)L_14)->max_length),NULL));
		if ((((int32_t)L_12) < ((int32_t)L_15)))
		{
			goto IL_0030;
		}
	}
	{
		NativeArray_1_t84C22AC03FE6517D060874E39A444D03469DD2F0 L_16 = V_1;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_17;
		L_17 = JobHandle_CombineDependencies_m5B482F42E4C9CAC22FF24C1BF76F3AFB870DBB3E(L_16, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_17));
		NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A((&V_1), NativeArray_1_Dispose_m410AE526181169A2E22E5508BF8072707268FC4A_RuntimeMethod_var);
		goto IL_0087;
	}

IL_006e:
	{
		bool L_18;
		L_18 = ((  bool (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, int32_t, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*, U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 11)))(__this, 0, (&V_4), (&V_0), NULL);
		if (L_18)
		{
			goto IL_007d;
		}
	}
	{
		return (bool)0;
	}

IL_007d:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_19 = V_4;
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_19));
	}

IL_0087:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_20 = __this->___m_Bones;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_21;
		L_21 = IL2CPP_NATIVEARRAY_GET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0);
		NullCheck(L_20);
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_22;
		L_22 = VertexBufferBones_ScheduleSortAndNormalizeBoneWeightsJob_mD358C4D61558BCB09ACFD05E2D32014CAD205835(L_20, L_21, NULL);
		IL2CPP_NATIVEARRAY_SET_ITEM(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08, ((&___1_handles))->___m_Buffer, 0, (L_22));
		return (bool)1;
	}
}
// Method Definition Index: 58122
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_CreateDescriptors_mA4F0EF69A3AB41D52085F9737A3884F1015F5F6F_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	{
		V_0 = 1;
		bool L_0 = __this->___m_HasNormals;
		if (!L_0)
		{
			goto IL_000e;
		}
	}
	{
		int32_t L_1 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_1, 1));
	}

IL_000e:
	{
		bool L_2 = __this->___m_HasTangents;
		if (!L_2)
		{
			goto IL_001a;
		}
	}
	{
		int32_t L_3 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_3, 1));
	}

IL_001a:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_4 = __this->___m_TexCoords;
		if (!L_4)
		{
			goto IL_0030;
		}
	}
	{
		int32_t L_5 = V_0;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		NullCheck(L_6);
		int32_t L_7;
		L_7 = VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline(L_6, NULL);
		V_0 = ((int32_t)il2cpp_codegen_add(L_5, L_7));
	}

IL_0030:
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_8 = __this->___m_Colors;
		if (!L_8)
		{
			goto IL_003c;
		}
	}
	{
		int32_t L_9 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_003c:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_10 = __this->___m_Bones;
		if (!L_10)
		{
			goto IL_0048;
		}
	}
	{
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 2));
	}

IL_0048:
	{
		int32_t L_12 = V_0;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_13 = (VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)(VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*)SZArrayNew(VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2_il2cpp_TypeInfo_var, (uint32_t)L_12);
		((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors = L_13;
		Il2CppCodeGenWriteBarrier((void**)(&((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors), (void*)L_13);
		V_1 = 0;
		V_2 = 0;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_14 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_15 = V_1;
		int32_t L_16 = V_2;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_17;
		memset((&L_17), 0, sizeof(L_17));
		VertexAttributeDescriptor__ctor_m713B31395FB13FDEB2665F5C4C31572D5875A43A((&L_17), 0, 0, 3, L_16, NULL);
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(L_15), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_17);
		int32_t L_18 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_18, 1));
		bool L_19 = __this->___m_HasNormals;
		if (!L_19)
		{
			goto IL_0092;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_20 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_21 = V_1;
		int32_t L_22 = V_2;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_23;
		memset((&L_23), 0, sizeof(L_23));
		VertexAttributeDescriptor__ctor_m713B31395FB13FDEB2665F5C4C31572D5875A43A((&L_23), 1, 0, 3, L_22, NULL);
		NullCheck(L_20);
		(L_20)->SetAt(static_cast<il2cpp_array_size_t>(L_21), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_23);
		int32_t L_24 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_24, 1));
	}

IL_0092:
	{
		bool L_25 = __this->___m_HasTangents;
		if (!L_25)
		{
			goto IL_00b3;
		}
	}
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_26 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_27 = V_1;
		int32_t L_28 = V_2;
		VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76 L_29;
		memset((&L_29), 0, sizeof(L_29));
		VertexAttributeDescriptor__ctor_m713B31395FB13FDEB2665F5C4C31572D5875A43A((&L_29), 2, 0, 4, L_28, NULL);
		NullCheck(L_26);
		(L_26)->SetAt(static_cast<il2cpp_array_size_t>(L_27), (VertexAttributeDescriptor_tD4231FBF57335465D16308D2A18E8E83D36BFA76)L_29);
		int32_t L_30 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_30, 1));
	}

IL_00b3:
	{
		int32_t L_31 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_31, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_32 = __this->___m_Colors;
		if (!L_32)
		{
			goto IL_00da;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_33 = __this->___m_Colors;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_34 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_35 = V_1;
		int32_t L_36 = V_2;
		NullCheck(L_33);
		VertexBufferColors_AddDescriptors_m9044A5AA91D41DB1C2C11F9C4F2CD96EACA72277(L_33, L_34, L_35, L_36, NULL);
		int32_t L_37 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_37, 1));
		int32_t L_38 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_38, 1));
	}

IL_00da:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_39 = __this->___m_TexCoords;
		if (!L_39)
		{
			goto IL_00fa;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_40 = __this->___m_TexCoords;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_41 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_42 = V_2;
		NullCheck(L_40);
		VirtualActionInvoker3< VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2*, int32_t*, int32_t >::Invoke(6, L_40, L_41, (&V_1), L_42);
		int32_t L_43 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_43, 1));
	}

IL_00fa:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_44 = __this->___m_Bones;
		if (!L_44)
		{
			goto IL_0115;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_45 = __this->___m_Bones;
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_46 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		int32_t L_47 = V_1;
		int32_t L_48 = V_2;
		NullCheck(L_45);
		VertexBufferBones_AddDescriptors_mC6CB82E330C72295F0EBB23137C4BB088313E358(L_45, L_46, L_47, L_48, NULL);
	}

IL_0115:
	{
		return;
	}
}
// Method Definition Index: 58123
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_ApplyOnMesh_mED500EA07DAC8DAD2EDB8ACDE15C00A10318EFF2_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___0_msh, int32_t ___1_flags, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_0 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		if (L_0)
		{
			goto IL_000e;
		}
	}
	{
		((  void (*) (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 12)))(__this, NULL);
	}

IL_000e:
	{
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_1 = ___0_msh;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_2 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		int32_t L_3;
		L_3 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13)))(L_2, NULL);
		VertexAttributeDescriptorU5BU5D_t5D10E60612F12777F59B7E33939F9075DB0E02B2* L_4 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Descriptors;
		NullCheck(L_1);
		Mesh_SetVertexBufferParams_m8033EB85082C142DCE8B69FFBAD26D7DFB0330B2(L_1, L_3, L_4, NULL);
		V_0 = 0;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_5 = ___0_msh;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_6 = __this->___m_Data;
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_7 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		int32_t L_8;
		L_8 = ((  int32_t (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 13)))(L_7, NULL);
		int32_t L_9 = V_0;
		int32_t L_10 = ___1_flags;
		NullCheck(L_5);
		((  void (*) (Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18, int32_t, int32_t, int32_t, int32_t, int32_t, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14)))(L_5, L_6, 0, 0, L_8, L_9, L_10, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 14));
		int32_t L_11 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_11, 1));
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_12 = __this->___m_Colors;
		if (!L_12)
		{
			goto IL_0060;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_13 = __this->___m_Colors;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_14 = ___0_msh;
		int32_t L_15 = V_0;
		int32_t L_16 = ___1_flags;
		NullCheck(L_13);
		VertexBufferColors_ApplyOnMesh_m8CAF595997FE659058850CA888F57E2BC7400198(L_13, L_14, L_15, L_16, NULL);
		int32_t L_17 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_17, 1));
	}

IL_0060:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_18 = __this->___m_TexCoords;
		if (!L_18)
		{
			goto IL_007a;
		}
	}
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_19 = __this->___m_TexCoords;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_20 = ___0_msh;
		int32_t L_21 = V_0;
		int32_t L_22 = ___1_flags;
		NullCheck(L_19);
		VirtualActionInvoker3< Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4*, int32_t, int32_t >::Invoke(7, L_19, L_20, L_21, L_22);
		int32_t L_23 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_23, 1));
	}

IL_007a:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_24 = __this->___m_Bones;
		if (!L_24)
		{
			goto IL_0090;
		}
	}
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_25 = __this->___m_Bones;
		Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* L_26 = ___0_msh;
		int32_t L_27 = V_0;
		int32_t L_28 = ___1_flags;
		NullCheck(L_25);
		VertexBufferBones_ApplyOnMesh_m4FD840B46FA25DE56B1FA29CF62053C0FAA26799(L_25, L_26, L_27, L_28, NULL);
	}

IL_0090:
	{
		return;
	}
}
// Method Definition Index: 58124
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VertexBufferGenerator_1_Dispose_m7F8396D3755837F43218752397D6D2C8A5C40745_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, bool ___0_disposing, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B5_0 = NULL;
	VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* G_B4_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B8_0 = NULL;
	VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* G_B7_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B11_0 = NULL;
	VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* G_B10_0 = NULL;
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_0 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		bool L_1;
		L_1 = ((  bool (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 15)))(L_0, NULL);
		if (!L_1)
		{
			goto IL_0018;
		}
	}
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* L_2 = (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*)(&__this->___m_Data);
		((  void (*) (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18*, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16)))(L_2, il2cpp_rgctx_method(il2cpp_codegen_method_rgctx(method), 16));
	}

IL_0018:
	{
		bool L_3 = ___0_disposing;
		if (!L_3)
		{
			goto IL_004d;
		}
	}
	{
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_4 = __this->___m_Colors;
		VertexBufferColors_tEF6C015F453B9211A3317E5AF8A19E5CBC4EB1BA* L_5 = L_4;
		if (L_5)
		{
			G_B5_0 = L_5;
			goto IL_0027;
		}
		G_B4_0 = L_5;
	}
	{
		goto IL_002c;
	}

IL_0027:
	{
		NullCheck(G_B5_0);
		VertexBufferColors_Dispose_mC3DD6D3F6A2D0EE961835C502B684BF811A3A163(G_B5_0, NULL);
	}

IL_002c:
	{
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_6 = __this->___m_TexCoords;
		VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* L_7 = L_6;
		if (L_7)
		{
			G_B8_0 = L_7;
			goto IL_0038;
		}
		G_B7_0 = L_7;
	}
	{
		goto IL_003d;
	}

IL_0038:
	{
		NullCheck(G_B8_0);
		VertexBufferTexCoordsBase_Dispose_m39249F9187EC383F0FD005F3E796FE156F1FBC04(G_B8_0, NULL);
	}

IL_003d:
	{
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_8 = __this->___m_Bones;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_9 = L_8;
		if (L_9)
		{
			G_B11_0 = L_9;
			goto IL_0048;
		}
		G_B10_0 = L_9;
	}
	{
		return;
	}

IL_0048:
	{
		NullCheck(G_B11_0);
		VertexBufferBones_Dispose_m82B53B77541DA6A97C3FA0D5D51E732D9882D90E(G_B11_0, NULL);
	}

IL_004d:
	{
		return;
	}
}
// Method Definition Index: 58125
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool VertexBufferGenerator_1_U3CScheduleVertexBonesJobsU3Eg__ScheduleVertexBonesJobU7C27_0_mE649B0A6DF480A7F1F6FEBF94F3EAE40DEEB4429_fshared (VertexBufferGenerator_1_t12CC991EA372CE8C51236E887396D21122E256A0* __this, int32_t ___0_i, JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* ___1_handle, U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684* ___2_p, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* V_0 = NULL;
	Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		U3CU3Ec__DisplayClass27_0_tC5438F0C7F70E93117B880A790CF2C1472BDF684* L_0 = ___2_p;
		AttributesU5BU5D_t5C860716354995D8F8EFE4333024653F767B1322* L_1 = L_0->___attributes;
		int32_t L_2 = ___0_i;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_0 = L_4;
		VertexBufferBones_tC987D4A60BFAFBABC22E567509B61F8671154A94* L_5 = __this->___m_Bones;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_6 = V_0;
		NullCheck(L_6);
		int32_t L_7 = L_6->___WEIGHTS_0;
		Attributes_tF3D527A3E48D3CB6A2B47EB1E1AB904C40EB204B* L_8 = V_0;
		NullCheck(L_8);
		int32_t L_9 = L_8->___JOINTS_0;
		NullCheck((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_10;
		L_10 = VirtualFuncInvoker0< Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* >::Invoke(10, (VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this);
		int32_t L_11 = ___0_i;
		NullCheck(L_10);
		int32_t L_12 = L_11;
		int32_t L_13 = (L_10)->GetAt(static_cast<il2cpp_array_size_t>(L_12));
		RuntimeObject* L_14 = ((VertexBufferGeneratorBase_tB4E0269A1A1886691C552C9ADBFCF337484A00EC*)__this)->___m_Buffers;
		NullCheck(L_5);
		Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489 L_15;
		L_15 = VertexBufferBones_ScheduleVertexBonesJob_m22A29825D18AF2F4DF85CAB97E2DDBB3482F6940(L_5, L_7, L_9, L_13, L_14, NULL);
		V_1 = L_15;
		bool L_16;
		L_16 = Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline((&V_1), NULL);
		if (L_16)
		{
			goto IL_0041;
		}
	}
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_17 = ___1_handle;
		il2cpp_codegen_initobj(L_17, sizeof(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08));
		return (bool)0;
	}

IL_0041:
	{
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08* L_18 = ___1_handle;
		JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08 L_19;
		L_19 = Nullable_1_get_Value_m35132F34816B551520C24C7FE0A77D2DA8B59B73((&V_1), NULL);
		*(JobHandle_t5DF5F99902FED3C801A81C05205CEA6CE039EF08*)L_18 = L_19;
		return (bool)1;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 1255
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Double_GetHashCode_m3761FC05AD24D97A68FA1E8412A9454DF3880E32_inline (double* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	{
		double L_0 = *(__this);
		int64_t L_1;
		L_1 = BitConverter_DoubleToInt64Bits_m4F42741818550F9956B5FBAF88C051F4DE5B0AE6_inline(L_0, NULL);
		V_0 = L_1;
		int64_t L_2 = V_0;
		int64_t L_3 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(1,NULL));
		if ((((int64_t)((int64_t)(((int64_t)il2cpp_codegen_subtract(L_2, L_3))&((int64_t)(std::numeric_limits<int64_t>::max)())))) < ((int64_t)((int64_t)9218868437227405312LL))))
		{
			goto IL_002d;
		}
	}
	{
		int64_t L_4 = V_0;
		V_0 = ((int64_t)(L_4&((int64_t)9218868437227405312LL)));
	}

IL_002d:
	{
		int64_t L_5 = V_0;
		int32_t L_6 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(L_5,NULL));
		int64_t L_7 = V_0;
		int32_t L_8 = (il2cpp_codegen_conv<int32_t,int64_t,int64_t,false,false>(((int64_t)(L_7>>((int32_t)32))),NULL));
		return ((int32_t)(L_6^L_8));
	}
}
// Method Definition Index: 8516
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* NumberFormatInfo_get_NumberGroupSeparator_m0556B092AA471513B1EDC31C047712226D39BEB6_inline (NumberFormatInfo_t8E26808B202927FEBF9064FCFEEA4D6E076E6472* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		String_t* L_0 = __this->___numberGroupSeparator;
		return L_0;
	}
}
// Method Definition Index: 8045
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t ConstantHelper_GetByteWithAllBitsSet_m38E318296F5FB9BAE51C97C1AE058716CFC889D7_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint8_t V_0 = 0x0;
	{
		V_0 = (uint8_t)0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,uint8_t*,intptr_t,false,false>((&V_0),NULL));
		*(((int8_t*)L_0)) = ((int8_t)((int32_t)255));
		uint8_t L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 8046
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int8_t ConstantHelper_GetSByteWithAllBitsSet_mB6B97526769DCCB7B78CCF446F28AAB0D1B5CAE3_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int8_t V_0 = 0x0;
	{
		V_0 = (int8_t)0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int8_t*,intptr_t,false,false>((&V_0),NULL));
		*(((int8_t*)L_0)) = ((int8_t)(-1));
		int8_t L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 8047
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint16_t ConstantHelper_GetUInt16WithAllBitsSet_mD3E13D933A06059499F0E0CBE6798D72D175464A_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint16_t V_0 = 0;
	{
		V_0 = (uint16_t)0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,uint16_t*,intptr_t,false,false>((&V_0),NULL));
		*(((int16_t*)L_0)) = ((int16_t)((int32_t)65535));
		uint16_t L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 8048
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int16_t ConstantHelper_GetInt16WithAllBitsSet_m70C5F99E624490970E2D4093FE6E800D1849DDFC_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int16_t V_0 = 0;
	{
		V_0 = (int16_t)0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int16_t*,intptr_t,false,false>((&V_0),NULL));
		*(((int16_t*)L_0)) = ((int16_t)(-1));
		int16_t L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 8049
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t ConstantHelper_GetUInt32WithAllBitsSet_m78CBFE0C29CF227C16D2A9021972A0D54744BCAF_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint32_t V_0 = 0;
	{
		V_0 = 0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,uint32_t*,intptr_t,false,false>((&V_0),NULL));
		*(((int32_t*)L_0)) = (-1);
		uint32_t L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 8050
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t ConstantHelper_GetInt32WithAllBitsSet_m245101340DDE7277600327D319DF86F1FFEA4FD0_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int32_t V_0 = 0;
	{
		V_0 = 0;
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,int32_t*,intptr_t,false,false>((&V_0),NULL));
		*(((int32_t*)L_0)) = (-1);
		int32_t L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 8051
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint64_t ConstantHelper_GetUInt64WithAllBitsSet_mB7F3E046EE6B1B20C552BF7CF619416E239A5A96_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	uint64_t V_0 = 0;
	{
		int64_t L_0 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		V_0 = L_0;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,uint64_t*,intptr_t,false,false>((&V_0),NULL));
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>((-1),NULL));
		*(((int64_t*)L_1)) = L_2;
		uint64_t L_3 = V_0;
		return L_3;
	}
}
// Method Definition Index: 8052
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t ConstantHelper_GetInt64WithAllBitsSet_m56A9AB64BA5DDD9ECC99424875824591DEFD5C40_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	int64_t V_0 = 0;
	{
		int64_t L_0 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>(0,NULL));
		V_0 = L_0;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int64_t*,intptr_t,false,false>((&V_0),NULL));
		int64_t L_2 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>((-1),NULL));
		*(((int64_t*)L_1)) = L_2;
		int64_t L_3 = V_0;
		return L_3;
	}
}
// Method Definition Index: 8053
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float ConstantHelper_GetSingleWithAllBitsSet_m66FC11C0680F744EB8315278910061C9535818C0_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	float V_0 = 0.0f;
	{
		V_0 = (0.0f);
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,float*,intptr_t,false,false>((&V_0),NULL));
		*(((int32_t*)L_0)) = (-1);
		float L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 8054
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double ConstantHelper_GetDoubleWithAllBitsSet_mF43AF77A6C93B7590B35B20458E80F2BC66AD5F2_inline (const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	double V_0 = 0.0;
	{
		V_0 = (0.0);
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>((&V_0),NULL));
		int64_t L_1 = (il2cpp_codegen_conv<int64_t,int32_t,int32_t,false,false>((-1),NULL));
		*(((int64_t*)L_0)) = L_1;
		double L_2 = V_0;
		return L_2;
	}
}
// Method Definition Index: 58144
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t VertexBufferTexCoordsBase_get_UVSetCount_m6374618466887F499537E93684538AE94E95F285_inline (VertexBufferTexCoordsBase_tD4FB8C52AAF80656258EE2D6877A9E2899FEC8A0* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		int32_t L_0 = __this->___U3CUVSetCountU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 8063
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Vector_1_Equals_m1D6500596F9B825F39D474A32D7A6D5E14E22B8F_fshared_inline (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	CHECKED_LOCAL(classRgctxInit);
	CHECKED_LOCAL(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit);
	//<source_info:<no-source>:1>
	{
		RuntimeObject* L_0 = ___0_obj;
		if (((RuntimeObject*)IsInstSealed((RuntimeObject*)L_0, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0))))
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	{
		RuntimeObject* L_1 = ___0_obj;
		CHECKED_LOCAL_INIT(Vector_1_t2DEF63E613428E110D429967E5CA7DE8ADF91630_StaticInit,(il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)),il2cpp_codegen_runtime_class_init_inline);
		bool L_2;
		L_2 = ((  bool (*) (Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*, Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2, const RuntimeMethod*))il2cpp_codegen_get_direct_method_pointer(il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5)))(__this, ((*(Vector_1_t4FB40153F5AFF7BFDFB20E1BCB98343E42252AD2*)UnBox(L_1, il2cpp_rgctx_data(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 0)))), il2cpp_rgctx_method(CHECKED_LOCAL_INIT_PARAM(classRgctxInit,(il2cpp_codegen_method_rgctx(method)),il2cpp_codegen_initialized_method_rgctx,(method)), 5));
		return L_2;
	}
}
// Method Definition Index: 40598
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void* NativeArrayUnsafeUtility_GetUnsafeReadOnlyPtr_TisIl2CppFullySharedGenericStruct_m13C618FD69BBAB7D8C77632BF8A9116FCD17D234_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 ___0_nativeArray, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18 L_0 = ___0_nativeArray;
		void* L_1 = L_0.___m_Buffer;
		return L_1;
	}
}
// Method Definition Index: 2805
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR __CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* Array_Empty_TisIl2CppSharedGenericObject_m688909407CF299AE69145CC33ACB1E90C775C653_gshared_inline (const RuntimeMethod* method) 
{
	il2cpp_rgctx_method_init(method);
	CHECKED_LOCAL(EmptyArray_1_t6C301AAECD8237FCD6328D15A5BC0071D53D11A1_StaticInit);
	//<source_info:<no-source>:1>
	{
		CHECKED_LOCAL_INIT(EmptyArray_1_t6C301AAECD8237FCD6328D15A5BC0071D53D11A1_StaticInit,(il2cpp_rgctx_data(method->rgctx_data, 0)),il2cpp_codegen_runtime_class_init_inline);
		__CanonU5BU5D_tFF96AE6C231BB36A6CEE54CEEB72ED8E90201979* L_0 = ((EmptyArray_1_tF2F83411E5DC963DBFFD1F75B10B58A1ED224DD5_StaticFields*)il2cpp_codegen_static_fields_for(il2cpp_rgctx_data(method->rgctx_data, 0)))->___Value;
		return L_0;
	}
}
// Method Definition Index: 40493
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool NativeArray_1_get_IsCreated_m527A2C3B75C25BFF29D1D9EA88C81172FF4F5A5A_fshared_inline (NativeArray_1_tDB8B8DC66CC8E16ED6D9A8C75D2C1AFC80AC1E18* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		void* L_0 = __this->___m_Buffer;
		uintptr_t L_1 = (il2cpp_codegen_conv<uintptr_t,int32_t,int32_t,false,false>(0,NULL));
		return (bool)((((int32_t)((((intptr_t)L_0) == ((intptr_t)L_1))? 1 : 0)) == ((int32_t)0))? 1 : 0);
	}
}
// Method Definition Index: 1765
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m6578702C98214F7F52425ADD0766109D2BE9953B_inline (Nullable_1_t02CE5E70DFA26EDBAB3AB261067AE257C96B822F* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0 = __this->___hasValue;
		return L_0;
	}
}
// Method Definition Index: 1765
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Nullable_1_get_HasValue_m5E390FE1B37B443BEE9BE8F3FFC9A0974CCAC80C_inline (Nullable_1_t2153F26F688901E0795BA65DEA582FDC46AB9489* __this, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		bool L_0 = __this->___hasValue;
		return L_0;
	}
}
// Method Definition Index: 749
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int64_t BitConverter_DoubleToInt64Bits_m4F42741818550F9956B5FBAF88C051F4DE5B0AE6_inline (double ___0_value, const RuntimeMethod* method) 
{
	//<source_info:<no-source>:1>
	{
		uintptr_t L_0 = (il2cpp_codegen_conv<uintptr_t,double*,intptr_t,false,false>((&___0_value),NULL));
		int64_t L_1 = *(((int64_t*)L_0));
		return L_1;
	}
}
