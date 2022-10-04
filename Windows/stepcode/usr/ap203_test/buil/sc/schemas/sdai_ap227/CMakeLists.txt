# -----  GENERATED FILE  -----
# -----   Do not edit!   -----

# schema name: plant_spatial_configuration
# (short name: sdai_ap227)
# 333 entities, 49 types

# targets, logic, etc are within a set of macros shared by all schemas
include(${SC_CMAKE_DIR}/SC_CXX_schema_macros.cmake)
set(sdai_ap227_file_count 774)

PROJECT(sdai_ap227)
# list headers so they can be installed - entity, type, misc
set(sdai_ap227_entity_hdrs
     entity/SdaiPlant_spatial_configuration_date_assignment.h                    entity/SdaiCartesian_transformation_operator_3d.h                           
     entity/SdaiVersioned_action_request.h                                       entity/SdaiFaceted_brep.h                                                   
     entity/SdaiAction_directive.h                                               entity/SdaiPlane_angle_unit.h                                               
     entity/SdaiArea_measure_with_unit.h                                         entity/SdaiColour.h                                                         
     entity/SdaiLine_less_piping_system.h                                        entity/SdaiInterfering_shape_element.h                                      
     entity/SdaiPiping_component_class.h                                         entity/SdaiConnection_functional_classification.h                           
     entity/SdaiOffset_surface.h                                                 entity/SdaiPlant_spatial_configuration_change_assignment.h                  
     entity/SdaiAxis2_placement_2d.h                                             entity/SdaiProduct_related_product_category.h                               
     entity/SdaiHyperbola.h                                                      entity/SdaiShape_aspect_deriving_relationship.h                             
     entity/SdaiStructural_system.h                                              entity/SdaiUniform_surface.h                                                
     entity/SdaiAxis1_placement.h                                                entity/SdaiRational_b_spline_curve.h                                        
     entity/SdaiAction_request_assignment.h                                      entity/SdaiProcess_capability.h                                             
     entity/SdaiFace_bound.h                                                     entity/SdaiLength_measure_with_unit.h                                       
     entity/SdaiPlant_line_definition.h                                          entity/SdaiData_environment.h                                               
     entity/SdaiDirection.h                                                      entity/SdaiLine_plant_item_connection.h                                     
     entity/SdaiBoolean_result.h                                                 entity/SdaiGroup_relationship.h                                             
     entity/SdaiProduct_definition_formation_relationship.h                      entity/SdaiGroup_assignment.h                                               
     entity/SdaiPlant_spatial_configuration_document_reference.h                 entity/SdaiTime_unit.h                                                      
     entity/SdaiBounded_curve.h                                                  entity/SdaiOriented_edge.h                                                  
     entity/SdaiPerson.h                                                         entity/SdaiPlant_item_interference.h                                        
     entity/SdaiDesign_project.h                                                 entity/SdaiRevolved_area_solid.h                                            
     entity/SdaiConversion_based_unit.h                                          entity/SdaiFlange_fitting_neck_type_classification.h                        
     entity/SdaiPoint_on_surface.h                                               entity/SdaiProduct_definition_formation.h                                   
     entity/SdaiRepresentation_item.h                                            entity/SdaiDescriptive_representation_item.h                                
     entity/SdaiOffset_curve_3d.h                                                entity/SdaiApproval.h                                                       
     entity/SdaiBoundary_curve.h                                                 entity/SdaiGeometric_representation_context.h                               
     entity/SdaiAdvanced_csg_shape_representation.h                              entity/SdaiPerson_role.h                                                    
     entity/SdaiAction_status.h                                                  entity/SdaiApplication_context.h                                            
     entity/SdaiDate_and_time.h                                                  entity/SdaiApproval_date_time.h                                             
     entity/SdaiApproval_role.h                                                  entity/SdaiProduct_context.h                                                
     entity/SdaiSpherical_surface.h                                              entity/SdaiSupport_constraint_representation.h                              
     entity/SdaiInline_equipment.h                                               entity/SdaiApplication_protocol_definition.h                                
     entity/SdaiFlange_fitting_classification.h                                  entity/SdaiProduct_definition_formation_with_specified_source.h             
     entity/SdaiAmount_of_substance_measure_with_unit.h                          entity/SdaiHalf_space_solid.h                                               
     entity/SdaiAction_request_solution.h                                        entity/SdaiCartesian_transformation_operator.h                              
     entity/SdaiGeometric_set_replica.h                                          entity/SdaiPath.h                                                           
     entity/SdaiSpacer_fitting_classification.h                                  entity/SdaiOriented_open_shell.h                                            
     entity/SdaiRight_circular_cylinder.h                                        entity/SdaiSolid_angle_unit.h                                               
     entity/SdaiLine_plant_item_branch_connection.h                              entity/SdaiTopological_representation_item.h                                
     entity/SdaiConnected_face_set.h                                             entity/SdaiCoordinated_universal_time_offset.h                              
     entity/SdaiCurve_replica.h                                                  entity/SdaiExtruded_face_solid.h                                            
     entity/SdaiPlant_spatial_configuration_person_and_organization_assignment.h entity/SdaiQuasi_uniform_surface.h                                          
     entity/SdaiSurface_curve.h                                                  entity/SdaiSystem_classification.h                                          
     entity/SdaiAction_request_status.h                                          entity/SdaiGroup.h                                                          
     entity/SdaiPlant_item_connection.h                                          entity/SdaiB_spline_surface.h                                               
     entity/SdaiReparametrised_composite_curve_segment.h                         entity/SdaiPerson_and_organization_role.h                                   
     entity/SdaiPresentation_layer_assignment.h                                  entity/SdaiQuasi_uniform_curve.h                                            
     entity/SdaiSwept_surface.h                                                  entity/SdaiElbow_fitting_classification.h                                   
     entity/SdaiProperty_definition.h                                            entity/SdaiSpecialty_item_classification.h                                  
     entity/SdaiAngular_location.h                                               entity/SdaiPlant_item_weight_representation.h                               
     entity/SdaiPlant_spatial_configuration_person_assignment.h                  entity/SdaiComposite_curve_on_surface.h                                     
     entity/SdaiParabola.h                                                       entity/SdaiRectangular_composite_surface.h                                  
     entity/SdaiPiping_connector_classification.h                                entity/SdaiAmount_of_substance_unit.h                                       
     entity/SdaiElementary_surface.h                                             entity/SdaiSurface_of_linear_extrusion.h                                    
     entity/SdaiUniform_curve.h                                                  entity/SdaiBezier_curve.h                                                   
     entity/SdaiEdge_loop.h                                                      entity/SdaiCalendar_date.h                                                  
     entity/SdaiToroidal_surface.h                                               entity/SdaiEdge.h                                                           
     entity/SdaiConnector_end_type_classification.h                              entity/SdaiApproval_assignment.h                                            
     entity/SdaiProduct_definition_substitute.h                                  entity/SdaiVector.h                                                         
     entity/SdaiBounded_pcurve.h                                                 entity/SdaiIntersection_curve.h                                             
     entity/SdaiTrimmed_curve.h                                                  entity/SdaiProduct_definition_context.h                                     
     entity/SdaiSite_representation.h                                            entity/SdaiDimensional_characteristic_representation.h                      
     entity/SdaiExternally_defined_plant_item_definition.h                       entity/SdaiBounded_surface_curve.h                                          
     entity/SdaiRepresentation.h                                                 entity/SdaiAction_method.h                                                  
     entity/SdaiCharacterized_object.h                                           entity/SdaiProduct_category_relationship.h                                  
     entity/SdaiRepresentation_context.h                                         entity/SdaiPlane_angle_measure_with_unit.h                                  
     entity/SdaiVertex.h                                                         entity/SdaiProduct_definition_relationship.h                                
     entity/SdaiElectric_current_unit.h                                          entity/SdaiRepresentation_map.h                                             
     entity/SdaiEllipse.h                                                        entity/SdaiManifold_solid_brep.h                                            
     entity/SdaiSolid_model.h                                                    entity/SdaiContext_dependent_unit.h                                         
     entity/SdaiLoop.h                                                           entity/SdaiStream_design_case.h                                             
     entity/SdaiDocument_type.h                                                  entity/SdaiDocument_reference.h                                             
     entity/SdaiLine_branch_connection.h                                         entity/SdaiSwage_fitting_classification.h                                   
     entity/SdaiPlacement.h                                                      entity/SdaiShell_based_wireframe_model.h                                    
     entity/SdaiSite_feature.h                                                   entity/SdaiComposite_curve.h                                                
     entity/SdaiPre_defined_item.h                                               entity/SdaiReducer_fitting_classification.h                                 
     entity/SdaiConic.h                                                          entity/SdaiSite.h                                                           
     entity/SdaiChange_action.h                                                  entity/SdaiPipe_classification.h                                            
     entity/SdaiPiping_system.h                                                  entity/SdaiDimensional_exponents.h                                          
     entity/SdaiCatalogue.h                                                      entity/SdaiDocument.h                                                       
     entity/SdaiExternally_defined_classification.h                              entity/SdaiDegenerate_toroidal_surface.h                                    
     entity/SdaiPerson_and_organization_assignment.h                             entity/SdaiPiping_design_csg_shape_representation.h                         
     entity/SdaiMass_measure_with_unit.h                                         entity/SdaiBrep_with_voids.h                                                
     entity/SdaiValve_classification.h                                           entity/SdaiExternally_defined_item.h                                        
     entity/SdaiThermodynamic_temperature_unit.h                                 entity/SdaiOrganization_role.h                                              
     entity/SdaiStream_phase.h                                                   entity/SdaiPoint_on_curve.h                                                 
     entity/SdaiFunctionally_defined_transformation.h                            entity/SdaiMeasure_with_unit.h                                              
     entity/SdaiFace_surface.h                                                   entity/SdaiMaterial_property.h                                              
     entity/SdaiOriented_face.h                                                  entity/SdaiSurface_of_revolution.h                                          
     entity/SdaiClassification_assignment.h                                      entity/SdaiFace.h                                                           
     entity/SdaiOpen_shell.h                                                     entity/SdaiLine_termination_connection.h                                    
     entity/SdaiProperty_definition_relationship.h                               entity/SdaiCatalogue_item.h                                                 
     entity/SdaiEdge_curve.h                                                     entity/SdaiElectric_current_measure_with_unit.h                             
     entity/SdaiPoint_replica.h                                                  entity/SdaiProduct.h                                                        
     entity/SdaiPlant_item_route.h                                               entity/SdaiShape_aspect_relationship.h                                      
     entity/SdaiRectangular_trimmed_surface.h                                    entity/SdaiElectrical_system.h                                              
     entity/SdaiPlane.h                                                          entity/SdaiPlant_spatial_configuration_organization_assignment.h            
     entity/SdaiCircle.h                                                         entity/SdaiConnection_node.h                                                
     entity/SdaiHybrid_shape_representation.h                                    entity/SdaiLine.h                                                           
     entity/SdaiProperty_definition_representation.h                             entity/SdaiMaterial_property_representation.h                               
     entity/SdaiDesign_project_assignment.h                                      entity/SdaiReserved_space.h                                                 
     entity/SdaiGeometric_curve_set.h                                            entity/SdaiDocument_relationship.h                                          
     entity/SdaiPcurve.h                                                         entity/SdaiMake_from_usage_option.h                                         
     entity/SdaiType_qualifier.h                                                 entity/SdaiEvaluated_degenerate_pcurve.h                                    
     entity/SdaiSolid_angle_measure_with_unit.h                                  entity/SdaiInstrumentation_and_control_system.h                             
     entity/SdaiCurve.h                                                          entity/SdaiDirected_action.h                                                
     entity/SdaiOrganizational_project.h                                         entity/SdaiRequired_material_property.h                                     
     entity/SdaiDate.h                                                           entity/SdaiDate_time_role.h                                                 
     entity/SdaiRatio_unit.h                                                     entity/SdaiAction_relationship.h                                            
     entity/SdaiExtruded_area_solid.h                                            entity/SdaiPlant_line_segment_termination.h                                 
     entity/SdaiKnown_source.h                                                   entity/SdaiNamed_unit.h                                                     
     entity/SdaiPlant.h                                                          entity/SdaiDegenerate_pcurve.h                                              
     entity/SdaiColour_specification.h                                           entity/SdaiCurve_bounded_surface.h                                          
     entity/SdaiMaterial_designation.h                                           entity/SdaiClosed_shell.h                                                   
     entity/SdaiComposite_curve_segment.h                                        entity/SdaiQualified_representation_item.h                                  
     entity/SdaiSurface.h                                                        entity/SdaiPlant_spatial_configuration_date_and_time_assignment.h           
     entity/SdaiDefinitional_representation.h                                    entity/SdaiAction_method_relationship.h                                     
     entity/SdaiDate_role.h                                                      entity/SdaiProduct_definition_shape.h                                       
     entity/SdaiSi_unit.h                                                        entity/SdaiGeometric_set.h                                                  
     entity/SdaiBezier_surface.h                                                 entity/SdaiCsg_solid.h                                                      
     entity/SdaiProduct_material_composition_relationship.h                      entity/SdaiSwept_area_solid.h                                               
     entity/SdaiPurchase_assignment.h                                            entity/SdaiB_spline_curve_with_knots.h                                      
     entity/SdaiGeometric_representation_item.h                                  entity/SdaiConnection_motion_classification.h                               
     entity/SdaiDerived_unit_element.h                                           entity/SdaiDerived_unit.h                                                   
     entity/SdaiSeam_curve.h                                                     entity/SdaiAxis2_placement_3d.h                                             
     entity/SdaiRational_b_spline_surface.h                                      entity/SdaiProduct_definition_with_associated_documents.h                   
     entity/SdaiTorus.h                                                          entity/SdaiAssembly_component_usage.h                                       
     entity/SdaiOrganization.h                                                   entity/SdaiDimensional_location.h                                           
     entity/SdaiColour_rgb.h                                                     entity/SdaiBlank_fitting_classification.h                                   
     entity/SdaiProduct_definition_usage.h                                       entity/SdaiB_spline_surface_with_knots.h                                    
     entity/SdaiReference_geometry.h                                             entity/SdaiOriented_path.h                                                  
     entity/SdaiSystem_space.h                                                   entity/SdaiShape_representation.h                                           
     entity/SdaiPlant_spatial_configuration_action_request_assignment.h          entity/SdaiChange_item_id_assignment.h                                      
     entity/SdaiOrganization_assignment.h                                        entity/SdaiApproval_status.h                                                
     entity/SdaiCartesian_point.h                                                entity/SdaiDate_and_time_assignment.h                                       
     entity/SdaiHeat_tracing_representation.h                                    entity/SdaiPoint.h                                                          
     entity/SdaiAction_assignment.h                                              entity/SdaiProduct_definition.h                                             
     entity/SdaiElectrical_connector_classification.h                            entity/SdaiTruncated_pyramid.h                                              
     entity/SdaiSurface_patch.h                                                  entity/SdaiChange_to_assignment.h                                           
     entity/SdaiLength_unit.h                                                    entity/SdaiShape_aspect.h                                                   
     entity/SdaiSite_building.h                                                  entity/SdaiVolume_measure_with_unit.h                                       
     entity/SdaiApplication_context_element.h                                    entity/SdaiChange_from_assignment.h                                         
     entity/SdaiMeasure_representation_item.h                                    entity/SdaiRight_circular_cone.h                                            
     entity/SdaiThermodynamic_temperature_measure_with_unit.h                    entity/SdaiDate_assignment.h                                                
     entity/SdaiPolyline.h                                                       entity/SdaiApproval_person_organization.h                                   
     entity/SdaiName_assignment.h                                                entity/SdaiPiping_component_definition.h                                    
     entity/SdaiStructural_load_connector_classification.h                       entity/SdaiProduct_category.h                                               
     entity/SdaiPlant_spatial_configuration_approval_assignment.h                entity/SdaiRevolved_face_solid.h                                            
     entity/SdaiSurface_replica.h                                                entity/SdaiDucting_system.h                                                 
     entity/SdaiDerived_shape_aspect.h                                           entity/SdaiExecuted_action.h                                                
     entity/SdaiDocument_usage_constraint.h                                      entity/SdaiShape_dimension_representation.h                                 
     entity/SdaiCentre_of_symmetry.h                                             entity/SdaiOriented_closed_shell.h                                          
     entity/SdaiDimensional_size.h                                               entity/SdaiPerson_and_organization.h                                        
     entity/SdaiSwept_face_solid.h                                               entity/SdaiBounded_surface.h                                                
     entity/SdaiPerson_assignment.h                                              entity/SdaiRatio_measure_with_unit.h                                        
     entity/SdaiExternal_source.h                                                entity/SdaiAction.h                                                         
     entity/SdaiSphere.h                                                         entity/SdaiCylindrical_surface.h                                            
     entity/SdaiLocal_time.h                                                     entity/SdaiPipe_closure_fitting_classification.h                            
     entity/SdaiMass_unit.h                                                      entity/SdaiDescriptive_colour.h                                             
     entity/SdaiMaterial_designation_characterization.h                          entity/SdaiPlant_line_segment_definition.h                                  
     entity/SdaiPoly_loop.h                                                      entity/SdaiCatalogue_connector.h                                            
     entity/SdaiArea_unit.h                                                      entity/SdaiMapped_item.h                                                    
     entity/SdaiOffset_curve_2d.h                                                entity/SdaiShape_definition_representation.h                                
     entity/SdaiPlant_item_connector.h                                           entity/SdaiVolume_unit.h                                                    
     entity/SdaiConical_surface.h                                                entity/SdaiBlock.h                                                          
     entity/SdaiGlobal_unit_assigned_context.h                                   entity/SdaiTime_measure_with_unit.h                                         
     entity/SdaiB_spline_curve.h                                                    )

set(sdai_ap227_type_hdrs
     type/SdaiCharacterized_definition.h                                         type/SdaiDesign_project_item.h                                              
     type/SdaiPurchase_item.h                                                    type/SdaiClassification_item.h                                              
     type/SdaiCharacterized_product_definition.h                                 type/SdaiReversible_topology_item.h                                         
     type/SdaiAxis2_placement.h                                                  type/SdaiKnot_type_var.h                                                    
     type/SdaiPlant_spatial_configuration_organization_item.h                    type/SdaiTransition_code_var.h                                              
     type/SdaiChange_delta_item.h                                                type/SdaiPlant_spatial_configuration_dated_item.h                           
     type/SdaiMeasure_value.h                                                    type/SdaiPerson_organization_select.h                                       
     type/SdaiPreferred_surface_curve_representation_var.h                       type/SdaiCsg_select.h                                                       
     type/SdaiLayered_item.h                                                     type/SdaiPcurve_or_surface.h                                                
     type/SdaiPlant_spatial_configuration_document_item.h                        type/SdaiPlant_spatial_configuration_person_item.h                          
     type/SdaiB_spline_curve_form_var.h                                          type/SdaiDimensional_characteristic.h                                       
     type/SdaiSi_unit_name_var.h                                                 type/SdaiSource_item.h                                                      
     type/SdaiTrimming_preference_var.h                                          type/SdaiPlant_spatial_configuration_person_and_organization_item.h         
     type/SdaiVector_or_direction.h                                              type/SdaiApproval_item.h                                                    
     type/SdaiGeometric_set_select.h                                             type/SdaiB_spline_surface_form_var.h                                        
     type/SdaiPlant_spatial_configuration_date_and_time_item.h                   type/SdaiShell.h                                                            
     type/SdaiBoolean_operand.h                                                  type/SdaiChange_item.h                                                      
     type/SdaiDate_time_select.h                                                 type/SdaiCsg_primitive.h                                                    
     type/SdaiCurve_on_surface.h                                                 type/SdaiTrimming_select.h                                                  
     type/SdaiAhead_or_behind_var.h                                              type/SdaiAngle_relator_var.h                                                
     type/SdaiSource_var.h                                                       type/SdaiUnit.h                                                             
     type/SdaiCharacterized_material_property.h                                  type/SdaiReversible_topology.h                                              
     type/SdaiShape_definition.h                                                 type/SdaiBoolean_operator_var.h                                             
     type/SdaiSi_prefix_var.h                                                    type/SdaiValue_qualifier.h                                                  
     type/SdaiPlant_spatial_configuration_action_request_item.h                     )

set(sdai_ap227_misc_hdrs
     Sdaiclasses.h   schema.h
     SdaiPLANT_SPATIAL_CONFIGURATIONNames.h
     SdaiPLANT_SPATIAL_CONFIGURATION.h
   )

# install all headers
set(all_headers ${sdai_ap227_entity_hdrs} ${sdai_ap227_type_hdrs} ${sdai_ap227_misc_hdrs})
foreach( header_file ${all_headers} )
  set(curr_dir)
  get_filename_component(curr_dir ${header_file} PATH)
  get_filename_component(curr_name ${header_file} NAME)
  if (curr_dir)
    install( FILES ${header_file} DESTINATION "include/schemas/sdai_ap227/${curr_dir}" )
  else (curr_dir)
    install( FILES ${header_file} DESTINATION "include/schemas/sdai_ap227" )
  endif (curr_dir)
endforeach()
# implementation files - 3 lists

# unity build: #include small .cc files to reduce the number
# of translation units that must be compiled
if(SC_UNITY_BUILD)
  # turns off include statements within type and entity .cc's - the unity T.U.'s include a unity header
  add_definitions( -DSC_SDAI_UNITY_BUILD)
  set(sdai_ap227_entity_impls SdaiPLANT_SPATIAL_CONFIGURATION_unity_entities.cc)
  set(sdai_ap227_type_impls SdaiPLANT_SPATIAL_CONFIGURATION_unity_types.cc)
else(SC_UNITY_BUILD)
  set(sdai_ap227_entity_impls
     entity/SdaiPlant_spatial_configuration_date_assignment.cc                   entity/SdaiCartesian_transformation_operator_3d.cc                          
     entity/SdaiVersioned_action_request.cc                                      entity/SdaiFaceted_brep.cc                                                  
     entity/SdaiAction_directive.cc                                              entity/SdaiPlane_angle_unit.cc                                              
     entity/SdaiArea_measure_with_unit.cc                                        entity/SdaiColour.cc                                                        
     entity/SdaiLine_less_piping_system.cc                                       entity/SdaiInterfering_shape_element.cc                                     
     entity/SdaiPiping_component_class.cc                                        entity/SdaiConnection_functional_classification.cc                          
     entity/SdaiOffset_surface.cc                                                entity/SdaiPlant_spatial_configuration_change_assignment.cc                 
     entity/SdaiAxis2_placement_2d.cc                                            entity/SdaiProduct_related_product_category.cc                              
     entity/SdaiHyperbola.cc                                                     entity/SdaiShape_aspect_deriving_relationship.cc                            
     entity/SdaiStructural_system.cc                                             entity/SdaiUniform_surface.cc                                               
     entity/SdaiAxis1_placement.cc                                               entity/SdaiRational_b_spline_curve.cc                                       
     entity/SdaiAction_request_assignment.cc                                     entity/SdaiProcess_capability.cc                                            
     entity/SdaiFace_bound.cc                                                    entity/SdaiLength_measure_with_unit.cc                                      
     entity/SdaiPlant_line_definition.cc                                         entity/SdaiData_environment.cc                                              
     entity/SdaiDirection.cc                                                     entity/SdaiLine_plant_item_connection.cc                                    
     entity/SdaiBoolean_result.cc                                                entity/SdaiGroup_relationship.cc                                            
     entity/SdaiProduct_definition_formation_relationship.cc                     entity/SdaiGroup_assignment.cc                                              
     entity/SdaiPlant_spatial_configuration_document_reference.cc                entity/SdaiTime_unit.cc                                                     
     entity/SdaiBounded_curve.cc                                                 entity/SdaiOriented_edge.cc                                                 
     entity/SdaiPerson.cc                                                        entity/SdaiPlant_item_interference.cc                                       
     entity/SdaiDesign_project.cc                                                entity/SdaiRevolved_area_solid.cc                                           
     entity/SdaiConversion_based_unit.cc                                         entity/SdaiFlange_fitting_neck_type_classification.cc                       
     entity/SdaiPoint_on_surface.cc                                              entity/SdaiProduct_definition_formation.cc                                  
     entity/SdaiRepresentation_item.cc                                           entity/SdaiDescriptive_representation_item.cc                               
     entity/SdaiOffset_curve_3d.cc                                               entity/SdaiApproval.cc                                                      
     entity/SdaiBoundary_curve.cc                                                entity/SdaiGeometric_representation_context.cc                              
     entity/SdaiAdvanced_csg_shape_representation.cc                             entity/SdaiPerson_role.cc                                                   
     entity/SdaiAction_status.cc                                                 entity/SdaiApplication_context.cc                                           
     entity/SdaiDate_and_time.cc                                                 entity/SdaiApproval_date_time.cc                                            
     entity/SdaiApproval_role.cc                                                 entity/SdaiProduct_context.cc                                               
     entity/SdaiSpherical_surface.cc                                             entity/SdaiSupport_constraint_representation.cc                             
     entity/SdaiInline_equipment.cc                                              entity/SdaiApplication_protocol_definition.cc                               
     entity/SdaiFlange_fitting_classification.cc                                 entity/SdaiProduct_definition_formation_with_specified_source.cc            
     entity/SdaiAmount_of_substance_measure_with_unit.cc                         entity/SdaiHalf_space_solid.cc                                              
     entity/SdaiAction_request_solution.cc                                       entity/SdaiCartesian_transformation_operator.cc                             
     entity/SdaiGeometric_set_replica.cc                                         entity/SdaiPath.cc                                                          
     entity/SdaiSpacer_fitting_classification.cc                                 entity/SdaiOriented_open_shell.cc                                           
     entity/SdaiRight_circular_cylinder.cc                                       entity/SdaiSolid_angle_unit.cc                                              
     entity/SdaiLine_plant_item_branch_connection.cc                             entity/SdaiTopological_representation_item.cc                               
     entity/SdaiConnected_face_set.cc                                            entity/SdaiCoordinated_universal_time_offset.cc                             
     entity/SdaiCurve_replica.cc                                                 entity/SdaiExtruded_face_solid.cc                                           
     entity/SdaiPlant_spatial_configuration_person_and_organization_assignment.cc entity/SdaiQuasi_uniform_surface.cc                                         
     entity/SdaiSurface_curve.cc                                                 entity/SdaiSystem_classification.cc                                         
     entity/SdaiAction_request_status.cc                                         entity/SdaiGroup.cc                                                         
     entity/SdaiPlant_item_connection.cc                                         entity/SdaiB_spline_surface.cc                                              
     entity/SdaiReparametrised_composite_curve_segment.cc                        entity/SdaiPerson_and_organization_role.cc                                  
     entity/SdaiPresentation_layer_assignment.cc                                 entity/SdaiQuasi_uniform_curve.cc                                           
     entity/SdaiSwept_surface.cc                                                 entity/SdaiElbow_fitting_classification.cc                                  
     entity/SdaiProperty_definition.cc                                           entity/SdaiSpecialty_item_classification.cc                                 
     entity/SdaiAngular_location.cc                                              entity/SdaiPlant_item_weight_representation.cc                              
     entity/SdaiPlant_spatial_configuration_person_assignment.cc                 entity/SdaiComposite_curve_on_surface.cc                                    
     entity/SdaiParabola.cc                                                      entity/SdaiRectangular_composite_surface.cc                                 
     entity/SdaiPiping_connector_classification.cc                               entity/SdaiAmount_of_substance_unit.cc                                      
     entity/SdaiElementary_surface.cc                                            entity/SdaiSurface_of_linear_extrusion.cc                                   
     entity/SdaiUniform_curve.cc                                                 entity/SdaiBezier_curve.cc                                                  
     entity/SdaiEdge_loop.cc                                                     entity/SdaiCalendar_date.cc                                                 
     entity/SdaiToroidal_surface.cc                                              entity/SdaiEdge.cc                                                          
     entity/SdaiConnector_end_type_classification.cc                             entity/SdaiApproval_assignment.cc                                           
     entity/SdaiProduct_definition_substitute.cc                                 entity/SdaiVector.cc                                                        
     entity/SdaiBounded_pcurve.cc                                                entity/SdaiIntersection_curve.cc                                            
     entity/SdaiTrimmed_curve.cc                                                 entity/SdaiProduct_definition_context.cc                                    
     entity/SdaiSite_representation.cc                                           entity/SdaiDimensional_characteristic_representation.cc                     
     entity/SdaiExternally_defined_plant_item_definition.cc                      entity/SdaiBounded_surface_curve.cc                                         
     entity/SdaiRepresentation.cc                                                entity/SdaiAction_method.cc                                                 
     entity/SdaiCharacterized_object.cc                                          entity/SdaiProduct_category_relationship.cc                                 
     entity/SdaiRepresentation_context.cc                                        entity/SdaiPlane_angle_measure_with_unit.cc                                 
     entity/SdaiVertex.cc                                                        entity/SdaiProduct_definition_relationship.cc                               
     entity/SdaiElectric_current_unit.cc                                         entity/SdaiRepresentation_map.cc                                            
     entity/SdaiEllipse.cc                                                       entity/SdaiManifold_solid_brep.cc                                           
     entity/SdaiSolid_model.cc                                                   entity/SdaiContext_dependent_unit.cc                                        
     entity/SdaiLoop.cc                                                          entity/SdaiStream_design_case.cc                                            
     entity/SdaiDocument_type.cc                                                 entity/SdaiDocument_reference.cc                                            
     entity/SdaiLine_branch_connection.cc                                        entity/SdaiSwage_fitting_classification.cc                                  
     entity/SdaiPlacement.cc                                                     entity/SdaiShell_based_wireframe_model.cc                                   
     entity/SdaiSite_feature.cc                                                  entity/SdaiComposite_curve.cc                                               
     entity/SdaiPre_defined_item.cc                                              entity/SdaiReducer_fitting_classification.cc                                
     entity/SdaiConic.cc                                                         entity/SdaiSite.cc                                                          
     entity/SdaiChange_action.cc                                                 entity/SdaiPipe_classification.cc                                           
     entity/SdaiPiping_system.cc                                                 entity/SdaiDimensional_exponents.cc                                         
     entity/SdaiCatalogue.cc                                                     entity/SdaiDocument.cc                                                      
     entity/SdaiExternally_defined_classification.cc                             entity/SdaiDegenerate_toroidal_surface.cc                                   
     entity/SdaiPerson_and_organization_assignment.cc                            entity/SdaiPiping_design_csg_shape_representation.cc                        
     entity/SdaiMass_measure_with_unit.cc                                        entity/SdaiBrep_with_voids.cc                                               
     entity/SdaiValve_classification.cc                                          entity/SdaiExternally_defined_item.cc                                       
     entity/SdaiThermodynamic_temperature_unit.cc                                entity/SdaiOrganization_role.cc                                             
     entity/SdaiStream_phase.cc                                                  entity/SdaiPoint_on_curve.cc                                                
     entity/SdaiFunctionally_defined_transformation.cc                           entity/SdaiMeasure_with_unit.cc                                             
     entity/SdaiFace_surface.cc                                                  entity/SdaiMaterial_property.cc                                             
     entity/SdaiOriented_face.cc                                                 entity/SdaiSurface_of_revolution.cc                                         
     entity/SdaiClassification_assignment.cc                                     entity/SdaiFace.cc                                                          
     entity/SdaiOpen_shell.cc                                                    entity/SdaiLine_termination_connection.cc                                   
     entity/SdaiProperty_definition_relationship.cc                              entity/SdaiCatalogue_item.cc                                                
     entity/SdaiEdge_curve.cc                                                    entity/SdaiElectric_current_measure_with_unit.cc                            
     entity/SdaiPoint_replica.cc                                                 entity/SdaiProduct.cc                                                       
     entity/SdaiPlant_item_route.cc                                              entity/SdaiShape_aspect_relationship.cc                                     
     entity/SdaiRectangular_trimmed_surface.cc                                   entity/SdaiElectrical_system.cc                                             
     entity/SdaiPlane.cc                                                         entity/SdaiPlant_spatial_configuration_organization_assignment.cc           
     entity/SdaiCircle.cc                                                        entity/SdaiConnection_node.cc                                               
     entity/SdaiHybrid_shape_representation.cc                                   entity/SdaiLine.cc                                                          
     entity/SdaiProperty_definition_representation.cc                            entity/SdaiMaterial_property_representation.cc                              
     entity/SdaiDesign_project_assignment.cc                                     entity/SdaiReserved_space.cc                                                
     entity/SdaiGeometric_curve_set.cc                                           entity/SdaiDocument_relationship.cc                                         
     entity/SdaiPcurve.cc                                                        entity/SdaiMake_from_usage_option.cc                                        
     entity/SdaiType_qualifier.cc                                                entity/SdaiEvaluated_degenerate_pcurve.cc                                   
     entity/SdaiSolid_angle_measure_with_unit.cc                                 entity/SdaiInstrumentation_and_control_system.cc                            
     entity/SdaiCurve.cc                                                         entity/SdaiDirected_action.cc                                               
     entity/SdaiOrganizational_project.cc                                        entity/SdaiRequired_material_property.cc                                    
     entity/SdaiDate.cc                                                          entity/SdaiDate_time_role.cc                                                
     entity/SdaiRatio_unit.cc                                                    entity/SdaiAction_relationship.cc                                           
     entity/SdaiExtruded_area_solid.cc                                           entity/SdaiPlant_line_segment_termination.cc                                
     entity/SdaiKnown_source.cc                                                  entity/SdaiNamed_unit.cc                                                    
     entity/SdaiPlant.cc                                                         entity/SdaiDegenerate_pcurve.cc                                             
     entity/SdaiColour_specification.cc                                          entity/SdaiCurve_bounded_surface.cc                                         
     entity/SdaiMaterial_designation.cc                                          entity/SdaiClosed_shell.cc                                                  
     entity/SdaiComposite_curve_segment.cc                                       entity/SdaiQualified_representation_item.cc                                 
     entity/SdaiSurface.cc                                                       entity/SdaiPlant_spatial_configuration_date_and_time_assignment.cc          
     entity/SdaiDefinitional_representation.cc                                   entity/SdaiAction_method_relationship.cc                                    
     entity/SdaiDate_role.cc                                                     entity/SdaiProduct_definition_shape.cc                                      
     entity/SdaiSi_unit.cc                                                       entity/SdaiGeometric_set.cc                                                 
     entity/SdaiBezier_surface.cc                                                entity/SdaiCsg_solid.cc                                                     
     entity/SdaiProduct_material_composition_relationship.cc                     entity/SdaiSwept_area_solid.cc                                              
     entity/SdaiPurchase_assignment.cc                                           entity/SdaiB_spline_curve_with_knots.cc                                     
     entity/SdaiGeometric_representation_item.cc                                 entity/SdaiConnection_motion_classification.cc                              
     entity/SdaiDerived_unit_element.cc                                          entity/SdaiDerived_unit.cc                                                  
     entity/SdaiSeam_curve.cc                                                    entity/SdaiAxis2_placement_3d.cc                                            
     entity/SdaiRational_b_spline_surface.cc                                     entity/SdaiProduct_definition_with_associated_documents.cc                  
     entity/SdaiTorus.cc                                                         entity/SdaiAssembly_component_usage.cc                                      
     entity/SdaiOrganization.cc                                                  entity/SdaiDimensional_location.cc                                          
     entity/SdaiColour_rgb.cc                                                    entity/SdaiBlank_fitting_classification.cc                                  
     entity/SdaiProduct_definition_usage.cc                                      entity/SdaiB_spline_surface_with_knots.cc                                   
     entity/SdaiReference_geometry.cc                                            entity/SdaiOriented_path.cc                                                 
     entity/SdaiSystem_space.cc                                                  entity/SdaiShape_representation.cc                                          
     entity/SdaiPlant_spatial_configuration_action_request_assignment.cc         entity/SdaiChange_item_id_assignment.cc                                     
     entity/SdaiOrganization_assignment.cc                                       entity/SdaiApproval_status.cc                                               
     entity/SdaiCartesian_point.cc                                               entity/SdaiDate_and_time_assignment.cc                                      
     entity/SdaiHeat_tracing_representation.cc                                   entity/SdaiPoint.cc                                                         
     entity/SdaiAction_assignment.cc                                             entity/SdaiProduct_definition.cc                                            
     entity/SdaiElectrical_connector_classification.cc                           entity/SdaiTruncated_pyramid.cc                                             
     entity/SdaiSurface_patch.cc                                                 entity/SdaiChange_to_assignment.cc                                          
     entity/SdaiLength_unit.cc                                                   entity/SdaiShape_aspect.cc                                                  
     entity/SdaiSite_building.cc                                                 entity/SdaiVolume_measure_with_unit.cc                                      
     entity/SdaiApplication_context_element.cc                                   entity/SdaiChange_from_assignment.cc                                        
     entity/SdaiMeasure_representation_item.cc                                   entity/SdaiRight_circular_cone.cc                                           
     entity/SdaiThermodynamic_temperature_measure_with_unit.cc                   entity/SdaiDate_assignment.cc                                               
     entity/SdaiPolyline.cc                                                      entity/SdaiApproval_person_organization.cc                                  
     entity/SdaiName_assignment.cc                                               entity/SdaiPiping_component_definition.cc                                   
     entity/SdaiStructural_load_connector_classification.cc                      entity/SdaiProduct_category.cc                                              
     entity/SdaiPlant_spatial_configuration_approval_assignment.cc               entity/SdaiRevolved_face_solid.cc                                           
     entity/SdaiSurface_replica.cc                                               entity/SdaiDucting_system.cc                                                
     entity/SdaiDerived_shape_aspect.cc                                          entity/SdaiExecuted_action.cc                                               
     entity/SdaiDocument_usage_constraint.cc                                     entity/SdaiShape_dimension_representation.cc                                
     entity/SdaiCentre_of_symmetry.cc                                            entity/SdaiOriented_closed_shell.cc                                         
     entity/SdaiDimensional_size.cc                                              entity/SdaiPerson_and_organization.cc                                       
     entity/SdaiSwept_face_solid.cc                                              entity/SdaiBounded_surface.cc                                               
     entity/SdaiPerson_assignment.cc                                             entity/SdaiRatio_measure_with_unit.cc                                       
     entity/SdaiExternal_source.cc                                               entity/SdaiAction.cc                                                        
     entity/SdaiSphere.cc                                                        entity/SdaiCylindrical_surface.cc                                           
     entity/SdaiLocal_time.cc                                                    entity/SdaiPipe_closure_fitting_classification.cc                           
     entity/SdaiMass_unit.cc                                                     entity/SdaiDescriptive_colour.cc                                            
     entity/SdaiMaterial_designation_characterization.cc                         entity/SdaiPlant_line_segment_definition.cc                                 
     entity/SdaiPoly_loop.cc                                                     entity/SdaiCatalogue_connector.cc                                           
     entity/SdaiArea_unit.cc                                                     entity/SdaiMapped_item.cc                                                   
     entity/SdaiOffset_curve_2d.cc                                               entity/SdaiShape_definition_representation.cc                               
     entity/SdaiPlant_item_connector.cc                                          entity/SdaiVolume_unit.cc                                                   
     entity/SdaiConical_surface.cc                                               entity/SdaiBlock.cc                                                         
     entity/SdaiGlobal_unit_assigned_context.cc                                  entity/SdaiTime_measure_with_unit.cc                                        
     entity/SdaiB_spline_curve.cc                                                   )

  set(sdai_ap227_type_impls
     type/SdaiCharacterized_definition.cc                                        type/SdaiDesign_project_item.cc                                             
     type/SdaiPurchase_item.cc                                                   type/SdaiClassification_item.cc                                             
     type/SdaiCharacterized_product_definition.cc                                type/SdaiReversible_topology_item.cc                                        
     type/SdaiAxis2_placement.cc                                                 type/SdaiKnot_type_var.cc                                                   
     type/SdaiPlant_spatial_configuration_organization_item.cc                   type/SdaiTransition_code_var.cc                                             
     type/SdaiChange_delta_item.cc                                               type/SdaiPlant_spatial_configuration_dated_item.cc                          
     type/SdaiMeasure_value.cc                                                   type/SdaiPerson_organization_select.cc                                      
     type/SdaiPreferred_surface_curve_representation_var.cc                      type/SdaiCsg_select.cc                                                      
     type/SdaiLayered_item.cc                                                    type/SdaiPcurve_or_surface.cc                                               
     type/SdaiPlant_spatial_configuration_document_item.cc                       type/SdaiPlant_spatial_configuration_person_item.cc                         
     type/SdaiB_spline_curve_form_var.cc                                         type/SdaiDimensional_characteristic.cc                                      
     type/SdaiSi_unit_name_var.cc                                                type/SdaiSource_item.cc                                                     
     type/SdaiTrimming_preference_var.cc                                         type/SdaiPlant_spatial_configuration_person_and_organization_item.cc        
     type/SdaiVector_or_direction.cc                                             type/SdaiApproval_item.cc                                                   
     type/SdaiGeometric_set_select.cc                                            type/SdaiB_spline_surface_form_var.cc                                       
     type/SdaiPlant_spatial_configuration_date_and_time_item.cc                  type/SdaiShell.cc                                                           
     type/SdaiBoolean_operand.cc                                                 type/SdaiChange_item.cc                                                     
     type/SdaiDate_time_select.cc                                                type/SdaiCsg_primitive.cc                                                   
     type/SdaiCurve_on_surface.cc                                                type/SdaiTrimming_select.cc                                                 
     type/SdaiAhead_or_behind_var.cc                                             type/SdaiAngle_relator_var.cc                                               
     type/SdaiSource_var.cc                                                      type/SdaiUnit.cc                                                            
     type/SdaiCharacterized_material_property.cc                                 type/SdaiReversible_topology.cc                                             
     type/SdaiShape_definition.cc                                                type/SdaiBoolean_operator_var.cc                                            
     type/SdaiSi_prefix_var.cc                                                   type/SdaiValue_qualifier.cc                                                 
     type/SdaiPlant_spatial_configuration_action_request_item.cc                    )
endif(SC_UNITY_BUILD)

set( sdai_ap227_misc_impls
     SdaiAll.cc    compstructs.cc    schema.cc
     SdaiPLANT_SPATIAL_CONFIGURATION.cc
     SdaiPLANT_SPATIAL_CONFIGURATION.init.cc   )

set(schema_target_files ${sdai_ap227_entity_impls} ${sdai_ap227_type_impls} ${sdai_ap227_misc_impls})
SCHEMA_TARGETS("F:/VS2019/XXX-StepCode/Windows/stepcode/data/ap227/ap227.exp" "plant_spatial_configuration"
                 "${schema_target_files}")
