ISO-10303-21;							/* ISOのバージョンと枝番 */
HEADER;
/***************************************
 --- 
 ヘッダセクション
 --- 
*/

 FILE_DESCRIPTION(('FreeCAD Model'),'2;1');				/* ファイルの説明 */
 FILE_NAME('C:/Users/OKUI/Documents/cylindertest.step',			/* ファイル名情報、日時、著作者、ソフトウエア等*/
   '2020-10-14T10:28:54',('Author'),(''),
   'Open CASCADE STEP processor 7.3','FreeCAD','Unknown');
 FILE_SCHEMA(('AUTOMOTIVE_DESIGN { 1 0 10303 214 1 1 1 1 }'));	/* スキーマ情報, ヘッダで何を採用したか */
 ENDSEC;										/* ヘッダセクション　終了 */

DATA;
/***************************************
 --- 
 データセクション
 --- 
*/

 /**
  以降、アプリケーションの設定関連
 */
 #1 = APPLICATION_PROTOCOL_DEFINITION('international standard',
   'automotive_design',2000, #2);
 #2 = APPLICATION_CONTEXT(
   'core data for automotive mechanical design processes');

 /**
  トップレベルのエンティティ宣言
  #4 -> Property Definition
  #10 -> Shape Representation
 */
 #3 = SHAPE_DEFINITION_REPRESENTATION(#4,#10);


 /**
  * '' -> name(label)
  * '' -> description(text)
  * #5 -> definition
  * */
 #4 = PRODUCT_DEFINITION_SHAPE('','',#5);

 /**
  * 'design' -> id(identifer)
  * '' -> description(text)
  * #6 -> formation
  * #9 -> frame of reference
  * */
 #5 = PRODUCT_DEFINITION('design','',#6,#9);

 /**
  * '' -> id(identifier)
  * '' -> description(text)
  * '' -> of_product
  * */
 #6 = PRODUCT_DEFINITION_FORMATION('','',#7);

 /**
  * 'Body' -> id(identifer)
  * 'Body' -> name(label)
  * '' -> descritpion(text)
  * #8 -> frame_of_reference 
  * */
 #7 = PRODUCT('Body','Body','',(#8));

 /**
  * '' -> name(label)
  * #2 -> frame_of_reference
  * 'mechanical' -> descipline_type(label)
  * */
 #8 = PRODUCT_CONTEXT('',#2,'mechanical');

 /**
  * 'part definition' -> name(label)
  * #2 -> 'frame_of_reference'
  * 'design' -> life_cycle_stage
  * */
 #9 = PRODUCT_DEFINITION_CONTEXT('part definition',#2,'design');

 /**
  * '' -> name(label)
  * (#11, #15) -> items(set of representation_item)
  * #113 -> context_of_items(representation_context)
  * */
 #10 = ADVANCED_BREP_SHAPE_REPRESENTATION('',(#11,#15),#113);

 /**
  * '' -> name(label)
  * #12 -> location(cartesian_point)
  * #13 -> axis(direction)
  * #14 -> ref_direction(direction)
  * */
 #11 = AXIS2_PLACEMENT_3D('',#12,#13,#14);
 /**
  * '' -> name(label)
  * (0.,0.,0.) -> coordinates(LIST OF length_measure(REAL))
  * */
 #12 = CARTESIAN_POINT('',(0.,0.,0.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #13 = DIRECTION('',(0.,0.,1.));
 #14 = DIRECTION('',(1.,0.,-0.));

 /**
  * '' -> name(label)
  * #16 -> outer(closed_shell)
  * */
 #15 = MANIFOLD_SOLID_BREP('',#16);

 /**
  * '' -> name(label)
  * #17, #105, #109 -> cfs_faces(SET OF face) 
  * */
 #16 = CLOSED_SHELL('',(#17,#105,#109));


 /**
 * '' -> name(label)
 * (#18) -> bounds(SET OF face_bound)
 * #32 -> face_geometry(surface)
 * T. -> same_sense(BOOLEAN)
 * */
 #17 = ADVANCED_FACE('',(#18),#32,.T.);
 /**
  * '' -> name(label)
  * #19 -> bound(loop)
  * F. -> orientation(BOOLEAN)
  * */
 #18 = FACE_BOUND('',#19,.F.);

 /**
  * '' -> name(label)
  * (#20, ..., #78) -> LIST OF oriented_joint
  * */
 #19 = EDGE_LOOP('',(#20,#50,#77,#78));

/**
 * '' -> name(label)
 * * -> edge_start*(vertex)
 * * -> edge_end*(vertex)
 * #21 -> edge_element(edge)
 * T. -> orientation(BOOLEAN)
 * */
 #20 = ORIENTED_EDGE('',*,*,#21,.T.);

 /**
  * '' -> name(label)
  * #22 -> edge_start(vertex)
  * #24 -> edge_end(vertex)
  * #26 -> edge_geometry(curve)
  * T. -> same_sense(BOOLEAN)
  * */
 #21 = EDGE_CURVE('',#22,#24,#26,.T.);

 /**
  * '' ->
  * #23 -> vertex_geometry(point)
  * */
 #22 = VERTEX_POINT('',#23);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)EDGE_LOOP
  * '' ->
  * #25 -> vertex_geometry(point)
  * */
 #24 = VERTEX_POINT('',#25);


 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * 円柱の伸ばした先に関連する内容を表しているかも?
  * */
 #25 = CARTESIAN_POINT('',(13.09216,0.455283,50.));

 /**
  * '' ->
  * #27 -> curve_3d(curve)
  * (#31,#43) -> associated_geometry(LIST OF pcurve_of_surface)
  * .PCURVE_S1. -> master_representation(preferred_surface ENUM)
  *   ENUMの中身 (curve_3d, pcurve_s1, pcurve_s2);
  * 
  * つまり1次元の曲げ?
  * */
 #26 = SEAM_CURVE('',#27,(#31,#43),.PCURVE_S1.);


 /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * 
  * 1次元になにかを引っ張っている?
  * */
 #27 = LINE('',#28,#29);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * ※円に関連する内容を表しているかも?
  * */
 #28 = CARTESIAN_POINT('',(13.09216,0.455283,0.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #29 = VECTOR('',#30,1.);

  /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #30 = DIRECTION('',(0.,0.,1.));

 /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #31 = PCURVE('',#32,#37);

 /**
  * '' ->
  * #33 -> position(axis2_placement_3d)
  * 13.5 -> radius(positive_length_measure)
  * */
 #32 = CYLINDRICAL_SURFACE('',#33,13.527648);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #33 = AXIS2_PLACEMENT_3D('',#34,#35,#36);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #34 = CARTESIAN_POINT('',(-0.435488,0.455283,0.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #35 = DIRECTION('',(-0.,-0.,-1.));
 #36 = DIRECTION('',(1.,0.,0.));


 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #37 = DEFINITIONAL_REPRESENTATION('',(#38),#42);

 /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * */
 #38 = LINE('',#39,#40);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #39 = CARTESIAN_POINT('',(-0.,0.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #40 = VECTOR('',#41,1.);

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #41 = DIRECTION('',(-0.,-1.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #42 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );

 /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #43 = PCURVE('',#32,#44);


 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #44 = DEFINITIONAL_REPRESENTATION('',(#45),#49);

  /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * */
 #45 = LINE('',#46,#47);

  /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #46 = CARTESIAN_POINT('',(-6.28318530718,0.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #47 = VECTOR('',#48,1.);

  /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #48 = DIRECTION('',(-0.,-1.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #49 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
 PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );


 /**
  * '' -> 
  * * -> edge_start*(vertex)
  * * -> edge_end*(vertex)
  * #51 -> edge_element(edge)
  * T. -> orientation(BOOLEAN)
  */
 #50 = ORIENTED_EDGE('',*,*,#51,.T.);

  /**
  * '' -> name(label)
  * #22 -> edge_start(vertex)
  * #24 -> edge_end(vertex)
  * #26 -> edge_geometry(curve)
  * T. -> same_sense(BOOLEAN)
  * */
 #51 = EDGE_CURVE('',#24,#24,#52,.T.);


 /** 
  * '' ->
  * #53 -> curve_3d(curve)
  * (#58,#65) -> associated_geometry(LIST OF pcurve_or_surface)
  * PCURVE_S1. -> master_representation (ENUM)
  *  curve_3d,
       pcurve_s1,
       pcurve_s2
 */
 #52 = SURFACE_CURVE('',#53,(#58,#65),.PCURVE_S1.);

 /** 
  * '' ->
  * #54 -> position(axis2_placement)
  * 13.52 -> radius(positive_length_measure)
  * 
 */
 #53 = CIRCLE('',#54,13.527648);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #54 = AXIS2_PLACEMENT_3D('',#55,#56,#57);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #55 = CARTESIAN_POINT('',(-0.435488,0.455283,50.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #56 = DIRECTION('',(0.,0.,1.));
 #57 = DIRECTION('',(1.,0.,0.));


 /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #58 = PCURVE('',#32,#59);

 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #59 = DEFINITIONAL_REPRESENTATION('',(#60),#64);

 /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * */
 #60 = LINE('',#61,#62);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #61 = CARTESIAN_POINT('',(-0.,-50.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #62 = VECTOR('',#63,1.);


 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #63 = DIRECTION('',(-1.,0.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #64 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );

   /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #65 = PCURVE('',#66,#71);


 /**
  * '' ->
  * #95 -> position(axis2_placement_3d)
  * */
 #66 = PLANE('',#67);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #67 = AXIS2_PLACEMENT_3D('',#68,#69,#70);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #68 = CARTESIAN_POINT('',(-0.435488,0.455283,50.));

  /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #69 = DIRECTION('',(0.,0.,1.));
 #70 = DIRECTION('',(1.,0.,0.));

 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #71 = DEFINITIONAL_REPRESENTATION('',(#72),#76);

 /** 
  * '' ->
  * #54 -> position(axis2_placement)
  * 13.52 -> radius(positive_length_measure)
  * 
 */
 #72 = CIRCLE('',#73,13.527648);


  /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
  #73 = AXIS2_PLACEMENT_2D('',#74,#75);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #74 = CARTESIAN_POINT('',(6.661338147751E-16,-5.551115123126E-17));

  /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #75 = DIRECTION('',(1.,0.));


 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #76 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );


 /**
  * '' -> 
  * * -> edge_start*(vertex)
  * * -> edge_end*(vertex)
  * #51 -> edge_element(edge)
  * T. -> orientation(BOOLEAN)
  */
 #77 = ORIENTED_EDGE('',*,*,#21,.F.);
 #78 = ORIENTED_EDGE('',*,*,#79,.F.);


 /**
  * '' -> name(label)
  * #22 -> edge_start(vertex)
  * #24 -> edge_end(vertex)
  * #26 -> edge_geometry(curve)
  * T. -> same_sense(BOOLEAN)
  * */
 #79 = EDGE_CURVE('',#22,#22,#80,.T.);


 /** 
  * '' ->
  * #53 -> curve_3d(curve)
  * (#58,#65) -> associated_geometry(LIST OF pcurve_or_surface)
  * PCURVE_S1. -> master_representation (ENUM)
  *  curve_3d,
       pcurve_s1,
       pcurve_s2
 */
 #80 = SURFACE_CURVE('',#81,(#86,#93),.PCURVE_S1.);

 /** 
  * '' ->
  * #54 -> position(axis2_placement)
  * 13.52 -> radius(positive_length_measure)
  * 
 */
 #81 = CIRCLE('',#82,13.527648);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #82 = AXIS2_PLACEMENT_3D('',#83,#84,#85);


 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #83 = CARTESIAN_POINT('',(-0.435488,0.455283,0.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #84 = DIRECTION('',(0.,0.,1.));
 #85 = DIRECTION('',(1.,0.,0.));

 /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #86 = PCURVE('',#32,#87);


 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #87 = DEFINITIONAL_REPRESENTATION('',(#88),#92);

 /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * */
 #88 = LINE('',#89,#90);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #89 = CARTESIAN_POINT('',(-0.,0.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #90 = VECTOR('',#91,1.);

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #91 = DIRECTION('',(-1.,0.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #92 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );

   /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #93 = PCURVE('',#94,#99);

 /**
  * '' ->
  * #95 -> position(axis2_placement_3d)
  * */
 #94 = PLANE('',#95);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #95 = AXIS2_PLACEMENT_3D('',#96,#97,#98);


 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #96 = CARTESIAN_POINT('',(-0.435488,0.455283,0.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #97 = DIRECTION('',(0.,0.,1.));
 #98 = DIRECTION('',(1.,0.,0.));

 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #99 = DEFINITIONAL_REPRESENTATION('',(#100),#104);

 /** 
  * '' ->
  * #54 -> position(axis2_placement)
  * 13.52 -> radius(positive_length_measure)
  * 
 */
 #100 = CIRCLE('',#101,13.527648);

  /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #101 = AXIS2_PLACEMENT_2D('',#102,#103);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #102 = CARTESIAN_POINT('',(6.661338147751E-16,-5.551115123126E-17));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #103 = DIRECTION('',(1.,0.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #104 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );

 /**
 * '' -> name(label)
 * (#18) -> bounds(SET OF face_bound)
 * #32 -> face_geometry(surface)
 * T. -> same_sense(BOOLEAN)
 * */
 #105 = ADVANCED_FACE('',(#106),#94,.F.);

 /**
  * '' -> name(label)
  * #19 -> bound(loop)
  * F. -> orientation(BOOLEAN)
  * */
 #106 = FACE_BOUND('',#107,.F.);

 /**
  * '' -> name(label)
  * (#20, ..., #78) -> LIST OF oriented_joint
  * */
 #107 = EDGE_LOOP('',(#108));

 /**
  * '' -> 
  * * -> edge_start*(vertex)
  * * -> edge_end*(vertex)
  * #51 -> edge_element(edge)
  * T. -> orientation(BOOLEAN)
  */
 #108 = ORIENTED_EDGE('',*,*,#79,.T.);

 /**
 * '' -> name(label)
 * (#18) -> bounds(SET OF face_bound)
 * #32 -> face_geometry(surface)
 * T. -> same_sense(BOOLEAN)
 * */
 #109 = ADVANCED_FACE('',(#110),#66,.T.);


 /**
  * '' -> name(label)
  * #19 -> bound(loop)
  * F. -> orientation(BOOLEAN)
  * */
 #110 = FACE_BOUND('',#111,.T.);


 /**
  * '' -> name(label)
  * (#20, ..., #78) -> LIST OF oriented_joint
  * */
 #111 = EDGE_LOOP('',(#112));

 /**
  * '' -> 
  * * -> edge_start*(vertex)
  * * -> edge_end*(vertex)
  * #51 -> edge_element(edge)
  * T. -> orientation(BOOLEAN)
  */
 #112 = ORIENTED_EDGE('',*,*,#51,.T.);


 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #113 = ( GEOMETRIC_REPRESENTATION_CONTEXT(3) 
GLOBAL_UNCERTAINTY_ASSIGNED_CONTEXT((#117)) GLOBAL_UNIT_ASSIGNED_CONTEXT
((#114,#115,#116)) REPRESENTATION_CONTEXT('Context #1',
  '3D Context with UNIT and UNCERTAINTY') );


 /** 
  * 単位系定義
  * */
 #114 = ( LENGTH_UNIT() NAMED_UNIT(*) SI_UNIT(.MILLI.,.METRE.) );
 #115 = ( NAMED_UNIT(*) PLANE_ANGLE_UNIT() SI_UNIT($,.RADIAN.) );
 #116 = ( NAMED_UNIT(*) SI_UNIT($,.STERADIAN.) SOLID_ANGLE_UNIT() );


 /**
  * LENGTH_MEASURE(...) -> value_component(meausre_value)
  * #114 -> unit_component(unit)
  * 'distance_accuracy_value' -> name(label)
  * 'confusion accuracy' -> description(text)
  * */
 #117 = UNCERTAINTY_MEASURE_WITH_UNIT(LENGTH_MEASURE(1.E-07),#114,
  'distance_accuracy_value','confusion accuracy');


/***
ここから
*/

/**
 * 'part' -> 
 * $ -> description(text)
 * #7 -> products(SET OF product)
 * */
#118 = PRODUCT_RELATED_PRODUCT_CATEGORY('part',$,(#7));

#119 = SHAPE_DEFINITION_REPRESENTATION(#120,#126);
#120 = PRODUCT_DEFINITION_SHAPE('','',#121);
#121 = PRODUCT_DEFINITION('design','',#122,#125);
#122 = PRODUCT_DEFINITION_FORMATION('','',#123);
#123 = PRODUCT('Sketch','Sketch','',(#124));
#124 = PRODUCT_CONTEXT('',#2,'mechanical');
#125 = PRODUCT_DEFINITION_CONTEXT('part definition',#2,'design');
/**
 * ここまでひとまとまり
 * */

 /** *
  * '' ->
  * (#11, ...) -> items(SET OF representation_item)
  * #136 -> context_of_items(representation)
  * */
 #126 = GEOMETRICALLY_BOUNDED_WIREFRAME_SHAPE_REPRESENTATION('',(#11,#127
    ),#136);


 /**
  * '' ->
  * (#128) -> elements(SET OF geometric_set_select)
  * */
 #127 = GEOMETRIC_CURVE_SET('',(#128));

 /**
  * '' ->
  * #129 -> basis_curve(curve)
  * (#134, ...) -> trim_1
  * (#135, ...) -> trim_2,
  * T. -> sense_agreement
  * PARAMETER. -> master_representation
  *  cartesian,
       parameter,
       unspecified);
  *  
  * */
 #128 = TRIMMED_CURVE('',#129,(#134,PARAMETER_VALUE(0.)),(#135,
    PARAMETER_VALUE(6.28318530718)),.T.,.PARAMETER.);

 /** 
  * '' ->
  * #54 -> position(axis2_placement)
  * 13.52 -> radius(positive_length_measure)
  * 
 */
 #129 = CIRCLE('',#130,13.527648);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #130 = AXIS2_PLACEMENT_3D('',#131,#132,#133);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #131 = CARTESIAN_POINT('',(-0.435488,0.455283,0.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #132 = DIRECTION('',(0.,0.,1.));
 #133 = DIRECTION('',(1.,0.,0.));

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #134 = CARTESIAN_POINT('',(13.09216,0.455283,0.));
 #135 = CARTESIAN_POINT('',(13.09216,0.455283,0.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #136 = ( GEOMETRIC_REPRESENTATION_CONTEXT(3) 
GLOBAL_UNCERTAINTY_ASSIGNED_CONTEXT((#140)) GLOBAL_UNIT_ASSIGNED_CONTEXT
((#137,#138,#139)) REPRESENTATION_CONTEXT('Context #1',
  '3D Context with UNIT and UNCERTAINTY') );


 /** 
  * 単位系定義
  * */
 #137 = ( LENGTH_UNIT() NAMED_UNIT(*) SI_UNIT(.MILLI.,.METRE.) );
 #138 = ( NAMED_UNIT(*) PLANE_ANGLE_UNIT() SI_UNIT($,.RADIAN.) );
 #139 = ( NAMED_UNIT(*) SI_UNIT($,.STERADIAN.) SOLID_ANGLE_UNIT() );

 /**
  * LENGTH_MEASURE(...) -> value_component(meausre_value)
  * #114 -> unit_component(unit)
  * 'distance_accuracy_value' -> name(label)
  * 'confusion accuracy' -> description(text)
  * */
 #140 = UNCERTAINTY_MEASURE_WITH_UNIT(LENGTH_MEASURE(1.E-07),#137,
  'distance_accuracy_value','confusion accuracy');

/***
ここから
*/
/**
 * 'part' -> 
 * $ -> description(text)
 * #7 -> products(SET OF product)
 * */
 #141 = PRODUCT_RELATED_PRODUCT_CATEGORY('part',$,(#123));

#142 = SHAPE_DEFINITION_REPRESENTATION(#143,#149);
#143 = PRODUCT_DEFINITION_SHAPE('','',#144);
#144 = PRODUCT_DEFINITION('design','',#145,#148);
#145 = PRODUCT_DEFINITION_FORMATION('','',#146);
#146 = PRODUCT('Pad','Pad','',(#147));
#147 = PRODUCT_CONTEXT('',#2,'mechanical');
#148 = PRODUCT_DEFINITION_CONTEXT('part definition',#2,'design');
/**
 * ここまで一まとまり
 * */




 /**
  * '' -> name(label)
  * (#11, #15) -> items(set of representation_item)
  * #113 -> context_of_items(representation_context)
  * */
 #149 = ADVANCED_BREP_SHAPE_REPRESENTATION('',(#11,#150),#248);

 /**
  * '' -> name(label)
  * #16 -> outer(closed_shell)
  * */
 #150 = MANIFOLD_SOLID_BREP('',#151);

 /**
  * '' -> name(label)
  * #17, #105, #109 -> cfs_faces(SET OF face) 
  * */
 #151 = CLOSED_SHELL('',(#152,#240,#244));

 /**
 * '' -> name(label)
 * (#18) -> bounds(SET OF face_bound)
 * #32 -> face_geometry(surface)
 * T. -> same_sense(BOOLEAN)
 * */
 #152 = ADVANCED_FACE('',(#153),#167,.T.);

 /**
  * '' -> name(label)
  * #19 -> bound(loop)
  * F. -> orientation(BOOLEAN)
  * */
 #153 = FACE_BOUND('',#154,.F.);


 /**
  * '' -> name(label)
  * (#20, ..., #78) -> LIST OF oriented_joint
  * */
 #154 = EDGE_LOOP('',(#155,#185,#212,#213));

 /**
  * '' -> 
  * * -> edge_start*(vertex)
  * * -> edge_end*(vertex)
  * #51 -> edge_element(edge)
  * T. -> orientation(BOOLEAN)
  */
 #155 = ORIENTED_EDGE('',*,*,#156,.T.);

 /**
  * '' -> name(label)
  * #22 -> edge_start(vertex)
  * #24 -> edge_end(vertex)
  * #26 -> edge_geometry(curve)
  * T. -> same_sense(BOOLEAN)
  * */
 #156 = EDGE_CURVE('',#157,#159,#161,.T.);


 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)EDGE_LOOP
  * '' ->
  * #25 -> vertex_geometry(point)
  * */
 #157 = VERTEX_POINT('',#158);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #158 = CARTESIAN_POINT('',(13.09216,0.455283,0.));


 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)EDGE_LOOP
  * '' ->
  * #25 -> vertex_geometry(point)
  * */
 #159 = VERTEX_POINT('',#160);


 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #160 = CARTESIAN_POINT('',(13.09216,0.455283,50.));

 /**
  * '' ->
  * #27 -> curve_3d(curve)
  * (#31,#43) -> associated_geometry(LIST OF pcurve_of_surface)
  * .PCURVE_S1. -> master_representation(preferred_surface ENUM)
  *   ENUMの中身 (curve_3d, pcurve_s1, pcurve_s2);
  * 
  * つまり1次元の曲げ?
  * */
 #161 = SEAM_CURVE('',#162,(#166,#178),.PCURVE_S1.);

 /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * */
 #162 = LINE('',#163,#164);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #163 = CARTESIAN_POINT('',(13.09216,0.455283,0.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #164 = VECTOR('',#165,1.);

  /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #165 = DIRECTION('',(0.,0.,1.));

 /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #166 = PCURVE('',#167,#172);


 /**
  * '' ->
  * #33 -> position(axis2_placement_3d)
  * 13.5 -> radius(positive_length_measure)
  * */
 #167 = CYLINDRICAL_SURFACE('',#168,13.527648);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #168 = AXIS2_PLACEMENT_3D('',#169,#170,#171);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #169 = CARTESIAN_POINT('',(-0.435488,0.455283,0.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #170 = DIRECTION('',(-0.,-0.,-1.));
 #171 = DIRECTION('',(1.,0.,0.));

 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #172 = DEFINITIONAL_REPRESENTATION('',(#173),#177);


 /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * */
 #173 = LINE('',#174,#175);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #174 = CARTESIAN_POINT('',(-0.,0.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #175 = VECTOR('',#176,1.);

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #176 = DIRECTION('',(-0.,-1.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #177 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );

 /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #178 = PCURVE('',#167,#179);


 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #179 = DEFINITIONAL_REPRESENTATION('',(#180),#184);

 /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * */
 #180 = LINE('',#181,#182);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #181 = CARTESIAN_POINT('',(-6.28318530718,0.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #182 = VECTOR('',#183,1.);

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #183 = DIRECTION('',(-0.,-1.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #184 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );

 /**
  * '' -> 
  * * -> edge_start*(vertex)
  * * -> edge_end*(vertex)
  * #51 -> edge_element(edge)
  * T. -> orientation(BOOLEAN)
  */
 #185 = ORIENTED_EDGE('',*,*,#186,.T.);


 /**
  * '' -> name(label)
  * #22 -> edge_start(vertex)
  * #24 -> edge_end(vertex)
  * #26 -> edge_geometry(curve)
  * T. -> same_sense(BOOLEAN)
  * */
 #186 = EDGE_CURVE('',#159,#159,#187,.T.);


 /** 
  * '' ->
  * #53 -> curve_3d(curve)
  * (#58,#65) -> associated_geometry(LIST OF pcurve_or_surface)
  * PCURVE_S1. -> master_representation (ENUM)
  *  curve_3d,
       pcurve_s1,
       pcurve_s2
 */
 #187 = SURFACE_CURVE('',#188,(#193,#200),.PCURVE_S1.);


  /** 
  * '' ->
  * #54 -> position(axis2_placement)
  * 13.52 -> radius(positive_length_measure)
  * 
  */
 #188 = CIRCLE('',#189,13.527648);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #189 = AXIS2_PLACEMENT_3D('',#190,#191,#192);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #190 = CARTESIAN_POINT('',(-0.435488,0.455283,50.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #191 = DIRECTION('',(0.,0.,1.));
 #192 = DIRECTION('',(1.,0.,0.));

  /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #193 = PCURVE('',#167,#194);

 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #194 = DEFINITIONAL_REPRESENTATION('',(#195),#199);

 /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * */
 #195 = LINE('',#196,#197);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #196 = CARTESIAN_POINT('',(-0.,-50.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #197 = VECTOR('',#198,1.);

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #198 = DIRECTION('',(-1.,0.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #199 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );

 /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #200 = PCURVE('',#201,#206);




 /**
  * '' ->
  * #95 -> position(axis2_placement_3d)
  * */
 #201 = PLANE('',#202);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #202 = AXIS2_PLACEMENT_3D('',#203,#204,#205);


 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
  #203 = CARTESIAN_POINT('',(-0.435488,0.455283,50.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #204 = DIRECTION('',(0.,0.,1.));
 #205 = DIRECTION('',(1.,0.,0.));

 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #206 = DEFINITIONAL_REPRESENTATION('',(#207),#211);


 /** 
  * '' ->
  * #54 -> position(axis2_placement)
  * 13.52 -> radius(positive_length_measure)
  * 
 */
 #207 = CIRCLE('',#208,13.527648);

  /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #208 = AXIS2_PLACEMENT_2D('',#209,#210);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #209 = CARTESIAN_POINT('',(6.661338147751E-16,-5.551115123126E-17));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #210 = DIRECTION('',(1.,0.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #211 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );

 /**
  * '' -> 
  * * -> edge_start*(vertex)
  * * -> edge_end*(vertex)
  * #51 -> edge_element(edge)
  * T. -> orientation(BOOLEAN)
  */
 #212 = ORIENTED_EDGE('',*,*,#156,.F.);
 #213 = ORIENTED_EDGE('',*,*,#214,.F.);

 /**
  * '' -> name(label)
  * #22 -> edge_start(vertex)
  * #24 -> edge_end(vertex)
  * #26 -> edge_geometry(curve)
  * T. -> same_sense(BOOLEAN)
  * */
 #214 = EDGE_CURVE('',#157,#157,#215,.T.);


 /** 
  * '' ->
  * #53 -> curve_3d(curve)
  * (#58,#65) -> associated_geometry(LIST OF pcurve_or_surface)
  * PCURVE_S1. -> master_representation (ENUM)
  *  curve_3d,
       pcurve_s1,
       pcurve_s2
 */
 #215 = SURFACE_CURVE('',#216,(#221,#228),.PCURVE_S1.);

 /** 
  * '' ->
  * #54 -> position(axis2_placement)
  * 13.52 -> radius(positive_length_measure)
  * 
 */
 #216 = CIRCLE('',#217,13.527648);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #217 = AXIS2_PLACEMENT_3D('',#218,#219,#220);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #218 = CARTESIAN_POINT('',(-0.435488,0.455283,0.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #219 = DIRECTION('',(0.,0.,1.));
 #220 = DIRECTION('',(1.,0.,0.));

 /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #221 = PCURVE('',#167,#222);


 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #222 = DEFINITIONAL_REPRESENTATION('',(#223),#227);


 /**
  * '' ->
  * #28 -> pnt(cartesian_point)
  * #29 -> dir(vector)
  * */
  #223 = LINE('',#224,#225);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #224 = CARTESIAN_POINT('',(-0.,0.));

 /**
  * '' ->
  * #30 -> orientation(direction)
  * 1. -> magnitude(length_measure)
  * */
 #225 = VECTOR('',#226,1.);

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #226 = DIRECTION('',(-1.,0.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #227 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );

  /**
  * '' ->
  * #32 -> basis_surface
  * #37 -> reference_to_curve
  * */
 #228 = PCURVE('',#229,#234);




 /**
  * '' ->
  * #95 -> position(axis2_placement_3d)
  * */
 #229 = PLANE('',#230);

 /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #230 = AXIS2_PLACEMENT_3D('',#231,#232,#233);

 /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #231 = CARTESIAN_POINT('',(-0.435488,0.455283,0.));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #232 = DIRECTION('',(0.,0.,1.));
 #233 = DIRECTION('',(1.,0.,0.));


 /**
  * '' ->
  * (#38) -> items(set of representation_item)
  * #42 -> context_of_items(representation_context)
  * */
 #234 = DEFINITIONAL_REPRESENTATION('',(#235),#239);

 /** 
  * '' ->
  * #54 -> position(axis2_placement)
  * 13.52 -> radius(positive_length_measure)
  * 
 */
 #235 = CIRCLE('',#236,13.527648);

  /**
  * ''->
  * #34 -> location(cartesian_point)
  * #35 -> axis(direction)
  * #36 -> ref_direction(direction)
  * */
 #236 = AXIS2_PLACEMENT_2D('',#237,#238);

  /**
  * '' ->
  * (...,...,...) -> coordinates(list of length_measure)
  * */
 #237 = CARTESIAN_POINT('',(6.661338147751E-16,-5.551115123126E-17));

 /**
  * '' -> name(label)
  * (A,B,C) -> direction_ratios
  * */
 #238 = DIRECTION('',(1.,0.));

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #239 = ( GEOMETRIC_REPRESENTATION_CONTEXT(2) 
PARAMETRIC_REPRESENTATION_CONTEXT() REPRESENTATION_CONTEXT('2D SPACE',''
  ) );


 /**
 * '' -> name(label)
 * (#18) -> bounds(SET OF face_bound)
 * #32 -> face_geometry(surface)
 * T. -> same_sense(BOOLEAN)
 * */
 #240 = ADVANCED_FACE('',(#241),#229,.F.);


 /**
  * '' -> name(label)
  * #19 -> bound(loop)
  * F. -> orientation(BOOLEAN)
  * */
 #241 = FACE_BOUND('',#242,.F.);

 /**
  * '' -> name(label)
  * (#20, ..., #78) -> LIST OF oriented_joint
  * */
 #242 = EDGE_LOOP('',(#243));



 /**
  * '' -> 
  * * -> edge_start*(vertex)
  * * -> edge_end*(vertex)
  * #51 -> edge_element(edge)
  * T. -> orientation(BOOLEAN)
  */
 #243 = ORIENTED_EDGE('',*,*,#214,.T.);

 /**
 * '' -> name(label)
 * (#18) -> bounds(SET OF face_bound)
 * #32 -> face_geometry(surface)
 * T. -> same_sense(BOOLEAN)
 * */
 #244 = ADVANCED_FACE('',(#245),#201,.T.);


 /**
  * '' -> name(label)
  * #19 -> bound(loop)
  * F. -> orientation(BOOLEAN)
  * */
 #245 = FACE_BOUND('',#246,.T.);


 /**
  * '' -> name(label)
  * (#20, ..., #78) -> LIST OF oriented_joint
  * */
 #246 = EDGE_LOOP('',(#247));

 /**
  * '' -> 
  * * -> edge_start*(vertex)
  * * -> edge_end*(vertex)
  * #51 -> edge_element(edge)
  * T. -> orientation(BOOLEAN)
  */
 #247 = ORIENTED_EDGE('',*,*,#186,.T.);

 /**
  * 以下の内容を一括的に決めている?
  * 文法の確認が必要
  * GEOMETRIC_REPRESENTATION_CONTEXT(2)   次元定義
  *  context_identifier(identifer)
  *  context_type(text)
  *  coordinate_space_dimension(dimension_count) ... ここのみが定義されている。次元を定義している
  * PARAMETRIC_REPRESENTATION_CONTEXT()
  *  context_identifier(identifier)
  *  context_type(text)
  * REPRESENTATION_CONTEXT            命名定義
  *  context_identifier(identifier)
  *  context_type(text)
  * */
 #248 = ( GEOMETRIC_REPRESENTATION_CONTEXT(3) 
GLOBAL_UNCERTAINTY_ASSIGNED_CONTEXT((#252)) GLOBAL_UNIT_ASSIGNED_CONTEXT
((#249,#250,#251)) REPRESENTATION_CONTEXT('Context #1',
  '3D Context with UNIT and UNCERTAINTY') );


 /** 
  * 単位系定義
  * */
 #249 = ( LENGTH_UNIT() NAMED_UNIT(*) SI_UNIT(.MILLI.,.METRE.) );
 #250 = ( NAMED_UNIT(*) PLANE_ANGLE_UNIT() SI_UNIT($,.RADIAN.) );
 #251 = ( NAMED_UNIT(*) SI_UNIT($,.STERADIAN.) SOLID_ANGLE_UNIT() );

 /**
  * LENGTH_MEASURE(...) -> value_component(meausre_value)
  * #114 -> unit_component(unit)
  * 'distance_accuracy_value' -> name(label)
  * 'confusion accuracy' -> description(text)
  * */
 #252 = UNCERTAINTY_MEASURE_WITH_UNIT(LENGTH_MEASURE(1.E-07),#249,
  'distance_accuracy_value','confusion accuracy');


/**
 * 'part' -> 
 * $ -> description(text)
 * #7 -> products(SET OF product)
 * */
#253 = PRODUCT_RELATED_PRODUCT_CATEGORY('part',$,(#146));

/**
 * 色付け関係
 * ひとまとまり **/

#254 = MECHANICAL_DESIGN_GEOMETRIC_PRESENTATION_REPRESENTATION('',(#255)
  ,#113);
#255 = STYLED_ITEM('color',(#256),#15);
#256 = PRESENTATION_STYLE_ASSIGNMENT((#257,#263));
#257 = SURFACE_STYLE_USAGE(.BOTH.,#258);
#258 = SURFACE_SIDE_STYLE('',(#259));
#259 = SURFACE_STYLE_FILL_AREA(#260);
#260 = FILL_AREA_STYLE('',(#261));
#261 = FILL_AREA_STYLE_COLOUR('',#262);
#262 = COLOUR_RGB('',0.800000011921,0.800000011921,0.800000011921);
#263 = CURVE_STYLE('',#264,POSITIVE_LENGTH_MEASURE(0.1),#262);
#264 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');

/**
 * 色付け関係
 * ひとまとまり **/

#265 = MECHANICAL_DESIGN_GEOMETRIC_PRESENTATION_REPRESENTATION('',(#266)
  ,#248);
#266 = STYLED_ITEM('color',(#267),#150);
#267 = PRESENTATION_STYLE_ASSIGNMENT((#268,#273));
#268 = SURFACE_STYLE_USAGE(.BOTH.,#269);
#269 = SURFACE_SIDE_STYLE('',(#270));
#270 = SURFACE_STYLE_FILL_AREA(#271);
#271 = FILL_AREA_STYLE('',(#272));
#272 = FILL_AREA_STYLE_COLOUR('',#262);
#273 = CURVE_STYLE('',#274,POSITIVE_LENGTH_MEASURE(0.1),#262);
#274 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');

/**
 * 色付け関係
 * ひとまとまり **/

#275 = MECHANICAL_DESIGN_GEOMETRIC_PRESENTATION_REPRESENTATION('',(#276)
  ,#136);
#276 = STYLED_ITEM('color',(#277),#127);
#277 = PRESENTATION_STYLE_ASSIGNMENT((#278,#283));
#278 = SURFACE_STYLE_USAGE(.BOTH.,#279);
#279 = SURFACE_SIDE_STYLE('',(#280));
#280 = SURFACE_STYLE_FILL_AREA(#281);
#281 = FILL_AREA_STYLE('',(#282));
#282 = FILL_AREA_STYLE_COLOUR('',#262);
#283 = CURVE_STYLE('',#284,POSITIVE_LENGTH_MEASURE(0.1),#262);
#284 = DRAUGHTING_PRE_DEFINED_CURVE_FONT('continuous');


ENDSEC;
END-ISO-10303-21;
