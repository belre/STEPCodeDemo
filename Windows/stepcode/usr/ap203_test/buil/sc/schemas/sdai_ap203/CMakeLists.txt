# -----  GENERATED FILE  -----
# -----   Do not edit!   -----

# schema name: config_control_design
# (short name: sdai_ap203)
# 254 entities, 42 types

# targets, logic, etc are within a set of macros shared by all schemas
include(${SC_CMAKE_DIR}/SC_CXX_schema_macros.cmake)
set(sdai_ap203_file_count 602)

PROJECT(sdai_ap203)
# list headers so they can be installed - entity, type, misc
set(sdai_ap203_entity_hdrs
     entity/SdaiCartesian_transformation_operator_3d.h                           entity/SdaiVersioned_action_request.h                                       
     entity/SdaiManifold_surface_shape_representation.h                          entity/SdaiCertification.h                                                  
     entity/SdaiQuantified_assembly_component_usage.h                            entity/SdaiFaceted_brep.h                                                   
     entity/SdaiAction_directive.h                                               entity/SdaiPlane_angle_unit.h                                               
     entity/SdaiArea_measure_with_unit.h                                         entity/SdaiSerial_numbered_effectivity.h                                    
     entity/SdaiOffset_surface.h                                                 entity/SdaiAxis2_placement_2d.h                                             
     entity/SdaiProduct_related_product_category.h                               entity/SdaiHyperbola.h                                                      
     entity/SdaiOrganizational_address.h                                         entity/SdaiUniform_surface.h                                                
     entity/SdaiGeometrically_bounded_surface_shape_representation.h             entity/SdaiAxis1_placement.h                                                
     entity/SdaiRational_b_spline_curve.h                                        entity/SdaiAction_request_assignment.h                                      
     entity/SdaiFace_bound.h                                                     entity/SdaiLength_measure_with_unit.h                                       
     entity/SdaiDated_effectivity.h                                              entity/SdaiDirection.h                                                      
     entity/SdaiNext_assembly_usage_occurrence.h                                 entity/SdaiBounded_curve.h                                                  
     entity/SdaiOriented_edge.h                                                  entity/SdaiPerson.h                                                         
     entity/SdaiDocument_with_class.h                                            entity/SdaiConversion_based_unit.h                                          
     entity/SdaiPoint_on_surface.h                                               entity/SdaiProduct_definition_formation.h                                   
     entity/SdaiRepresentation_item.h                                            entity/SdaiCc_design_person_and_organization_assignment.h                   
     entity/SdaiOffset_curve_3d.h                                                entity/SdaiApproval.h                                                       
     entity/SdaiBoundary_curve.h                                                 entity/SdaiGeometric_representation_context.h                               
     entity/SdaiAction_status.h                                                  entity/SdaiApplication_context.h                                            
     entity/SdaiChange_request.h                                                 entity/SdaiDate_and_time.h                                                  
     entity/SdaiApproval_date_time.h                                             entity/SdaiApproval_role.h                                                  
     entity/SdaiProduct_context.h                                                entity/SdaiSpherical_surface.h                                              
     entity/SdaiApplication_protocol_definition.h                                entity/SdaiSpecified_higher_usage_occurrence.h                              
     entity/SdaiProduct_definition_formation_with_specified_source.h             entity/SdaiAction_request_solution.h                                        
     entity/SdaiUncertainty_measure_with_unit.h                                  entity/SdaiEdge_based_wireframe_model.h                                     
     entity/SdaiCartesian_transformation_operator.h                              entity/SdaiPath.h                                                           
     entity/SdaiOriented_open_shell.h                                            entity/SdaiSolid_angle_unit.h                                               
     entity/SdaiTopological_representation_item.h                                entity/SdaiConnected_face_set.h                                             
     entity/SdaiCoordinated_universal_time_offset.h                              entity/SdaiCurve_replica.h                                                  
     entity/SdaiQuasi_uniform_surface.h                                          entity/SdaiSurface_curve.h                                                  
     entity/SdaiAction_request_status.h                                          entity/SdaiB_spline_surface.h                                               
     entity/SdaiReparametrised_composite_curve_segment.h                         entity/SdaiRepresentation_relationship_with_transformation.h                
     entity/SdaiPerson_and_organization_role.h                                   entity/SdaiQuasi_uniform_curve.h                                            
     entity/SdaiSwept_surface.h                                                  entity/SdaiProperty_definition.h                                            
     entity/SdaiGlobal_uncertainty_assigned_context.h                            entity/SdaiComposite_curve_on_surface.h                                     
     entity/SdaiOrganization_relationship.h                                      entity/SdaiParabola.h                                                       
     entity/SdaiRectangular_composite_surface.h                                  entity/SdaiElementary_surface.h                                             
     entity/SdaiLot_effectivity.h                                                entity/SdaiSurface_of_linear_extrusion.h                                    
     entity/SdaiShell_based_surface_model.h                                      entity/SdaiUniform_curve.h                                                  
     entity/SdaiBezier_curve.h                                                   entity/SdaiEdge_loop.h                                                      
     entity/SdaiCalendar_date.h                                                  entity/SdaiToroidal_surface.h                                               
     entity/SdaiEdge.h                                                           entity/SdaiPromissory_usage_occurrence.h                                    
     entity/SdaiApproval_assignment.h                                            entity/SdaiConfiguration_item.h                                             
     entity/SdaiContract_assignment.h                                            entity/SdaiVector.h                                                         
     entity/SdaiBounded_pcurve.h                                                 entity/SdaiIntersection_curve.h                                             
     entity/SdaiTrimmed_curve.h                                                  entity/SdaiProduct_definition_context.h                                     
     entity/SdaiBounded_surface_curve.h                                          entity/SdaiItem_defined_transformation.h                                    
     entity/SdaiRepresentation.h                                                 entity/SdaiAction_method.h                                                  
     entity/SdaiProduct_category_relationship.h                                  entity/SdaiRepresentation_context.h                                         
     entity/SdaiPlane_angle_measure_with_unit.h                                  entity/SdaiVertex.h                                                         
     entity/SdaiProduct_definition_relationship.h                                entity/SdaiRepresentation_map.h                                             
     entity/SdaiConfiguration_effectivity.h                                      entity/SdaiEllipse.h                                                        
     entity/SdaiManifold_solid_brep.h                                            entity/SdaiSolid_model.h                                                    
     entity/SdaiContext_dependent_unit.h                                         entity/SdaiLoop.h                                                           
     entity/SdaiAlternate_product_relationship.h                                 entity/SdaiDocument_type.h                                                  
     entity/SdaiDocument_reference.h                                             entity/SdaiMechanical_context.h                                             
     entity/SdaiPlacement.h                                                      entity/SdaiShell_based_wireframe_model.h                                    
     entity/SdaiComposite_curve.h                                                entity/SdaiConic.h                                                          
     entity/SdaiContract.h                                                       entity/SdaiDimensional_exponents.h                                          
     entity/SdaiStart_request.h                                                  entity/SdaiCc_design_specification_reference.h                              
     entity/SdaiEffectivity.h                                                    entity/SdaiSupplied_part_relationship.h                                     
     entity/SdaiDocument.h                                                       entity/SdaiContext_dependent_shape_representation.h                         
     entity/SdaiDegenerate_toroidal_surface.h                                    entity/SdaiPerson_and_organization_assignment.h                             
     entity/SdaiOrdinal_date.h                                                   entity/SdaiFace_outer_bound.h                                               
     entity/SdaiMass_measure_with_unit.h                                         entity/SdaiBrep_with_voids.h                                                
     entity/SdaiWeek_of_year_and_day_date.h                                      entity/SdaiPoint_on_curve.h                                                 
     entity/SdaiShell_based_wireframe_shape_representation.h                     entity/SdaiFunctionally_defined_transformation.h                            
     entity/SdaiMeasure_with_unit.h                                              entity/SdaiFace_surface.h                                                   
     entity/SdaiOriented_face.h                                                  entity/SdaiSurface_of_revolution.h                                          
     entity/SdaiAdvanced_brep_shape_representation.h                             entity/SdaiFace.h                                                           
     entity/SdaiOpen_shell.h                                                     entity/SdaiEdge_curve.h                                                     
     entity/SdaiPoint_replica.h                                                  entity/SdaiProduct.h                                                        
     entity/SdaiShape_aspect_relationship.h                                      entity/SdaiRectangular_trimmed_surface.h                                    
     entity/SdaiPlane.h                                                          entity/SdaiChange.h                                                         
     entity/SdaiCircle.h                                                         entity/SdaiLine.h                                                           
     entity/SdaiProperty_definition_representation.h                             entity/SdaiGeometric_curve_set.h                                            
     entity/SdaiPersonal_address.h                                               entity/SdaiDocument_relationship.h                                          
     entity/SdaiPcurve.h                                                         entity/SdaiOuter_boundary_curve.h                                           
     entity/SdaiRepresentation_relationship.h                                    entity/SdaiShape_representation_relationship.h                              
     entity/SdaiAssembly_component_usage_substitute.h                            entity/SdaiEvaluated_degenerate_pcurve.h                                    
     entity/SdaiSolid_angle_measure_with_unit.h                                  entity/SdaiConnected_edge_set.h                                             
     entity/SdaiCurve.h                                                          entity/SdaiDirected_action.h                                                
     entity/SdaiOrganizational_project.h                                         entity/SdaiDate.h                                                           
     entity/SdaiDate_time_role.h                                                 entity/SdaiNamed_unit.h                                                     
     entity/SdaiDegenerate_pcurve.h                                              entity/SdaiCurve_bounded_surface.h                                          
     entity/SdaiClosed_shell.h                                                   entity/SdaiComposite_curve_segment.h                                        
     entity/SdaiDesign_make_from_relationship.h                                  entity/SdaiSurface.h                                                        
     entity/SdaiDefinitional_representation.h                                    entity/SdaiProduct_definition_shape.h                                       
     entity/SdaiSi_unit.h                                                        entity/SdaiGeometric_set.h                                                  
     entity/SdaiBezier_surface.h                                                 entity/SdaiCertification_assignment.h                                       
     entity/SdaiStart_work.h                                                     entity/SdaiContract_type.h                                                  
     entity/SdaiB_spline_curve_with_knots.h                                      entity/SdaiGeometric_representation_item.h                                  
     entity/SdaiCc_design_approval.h                                             entity/SdaiEdge_based_wireframe_shape_representation.h                      
     entity/SdaiGeometrically_bounded_wireframe_shape_representation.h           entity/SdaiProduct_concept.h                                                
     entity/SdaiCc_design_contract.h                                             entity/SdaiSeam_curve.h                                                     
     entity/SdaiAxis2_placement_3d.h                                             entity/SdaiRational_b_spline_surface.h                                      
     entity/SdaiConfiguration_design.h                                           entity/SdaiDesign_context.h                                                 
     entity/SdaiProduct_definition_with_associated_documents.h                   entity/SdaiAssembly_component_usage.h                                       
     entity/SdaiOrganization.h                                                   entity/SdaiCc_design_certification.h                                        
     entity/SdaiProduct_definition_usage.h                                       entity/SdaiB_spline_surface_with_knots.h                                    
     entity/SdaiCertification_type.h                                             entity/SdaiOriented_path.h                                                  
     entity/SdaiSecurity_classification.h                                        entity/SdaiShape_representation.h                                           
     entity/SdaiVertex_loop.h                                                    entity/SdaiApproval_status.h                                                
     entity/SdaiCartesian_point.h                                                entity/SdaiDate_and_time_assignment.h                                       
     entity/SdaiPoint.h                                                          entity/SdaiAction_assignment.h                                              
     entity/SdaiProduct_definition.h                                             entity/SdaiParametric_representation_context.h                              
     entity/SdaiProduct_concept_context.h                                        entity/SdaiSurface_patch.h                                                  
     entity/SdaiLength_unit.h                                                    entity/SdaiShape_aspect.h                                                   
     entity/SdaiVolume_measure_with_unit.h                                       entity/SdaiApplication_context_element.h                                    
     entity/SdaiAdvanced_face.h                                                  entity/SdaiSecurity_classification_level.h                                  
     entity/SdaiApproval_relationship.h                                          entity/SdaiPolyline.h                                                       
     entity/SdaiApproval_person_organization.h                                   entity/SdaiProduct_definition_effectivity.h                                 
     entity/SdaiProduct_category.h                                               entity/SdaiSurface_replica.h                                                
     entity/SdaiAddress.h                                                        entity/SdaiCc_design_security_classification.h                              
     entity/SdaiExecuted_action.h                                                entity/SdaiFaceted_brep_shape_representation.h                              
     entity/SdaiDocument_usage_constraint.h                                      entity/SdaiVertex_point.h                                                   
     entity/SdaiCc_design_date_and_time_assignment.h                             entity/SdaiOriented_closed_shell.h                                          
     entity/SdaiPerson_and_organization.h                                        entity/SdaiBounded_surface.h                                                
     entity/SdaiAction.h                                                         entity/SdaiCylindrical_surface.h                                            
     entity/SdaiLocal_time.h                                                     entity/SdaiMass_unit.h                                                      
     entity/SdaiVertex_shell.h                                                   entity/SdaiPoly_loop.h                                                      
     entity/SdaiWire_shell.h                                                     entity/SdaiArea_unit.h                                                      
     entity/SdaiMapped_item.h                                                    entity/SdaiShape_definition_representation.h                                
     entity/SdaiVolume_unit.h                                                    entity/SdaiConical_surface.h                                                
     entity/SdaiSecurity_classification_assignment.h                             entity/SdaiFounded_item.h                                                   
     entity/SdaiGlobal_unit_assigned_context.h                                   entity/SdaiB_spline_curve.h                                                 
        )

set(sdai_ap203_type_hdrs
     type/SdaiCharacterized_definition.h                                         type/SdaiChange_request_item.h                                              
     type/SdaiCharacterized_product_definition.h                                 type/SdaiReversible_topology_item.h                                         
     type/SdaiAxis2_placement.h                                                  type/SdaiKnot_type_var.h                                                    
     type/SdaiSpecified_item.h                                                   type/SdaiTransition_code_var.h                                              
     type/SdaiMeasure_value.h                                                    type/SdaiPerson_organization_select.h                                       
     type/SdaiPreferred_surface_curve_representation_var.h                       type/SdaiPcurve_or_surface.h                                                
     type/SdaiB_spline_curve_form_var.h                                          type/SdaiClassified_item.h                                                  
     type/SdaiSi_unit_name_var.h                                                 type/SdaiFounded_item_select.h                                              
     type/SdaiTrimming_preference_var.h                                          type/SdaiVector_or_direction.h                                              
     type/SdaiWireframe_model.h                                                  type/SdaiGeometric_set_select.h                                             
     type/SdaiStart_request_item.h                                               type/SdaiB_spline_surface_form_var.h                                        
     type/SdaiPerson_organization_item.h                                         type/SdaiDate_time_item.h                                                   
     type/SdaiShell.h                                                            type/SdaiTransformation.h                                                   
     type/SdaiBoolean_operand.h                                                  type/SdaiCertified_item.h                                                   
     type/SdaiDate_time_select.h                                                 type/SdaiCurve_on_surface.h                                                 
     type/SdaiTrimming_select.h                                                  type/SdaiAhead_or_behind_var.h                                              
     type/SdaiContracted_item.h                                                  type/SdaiSource_var.h                                                       
     type/SdaiUnit.h                                                             type/SdaiReversible_topology.h                                              
     type/SdaiWork_item.h                                                        type/SdaiShape_definition.h                                                 
     type/SdaiSupported_item.h                                                   type/SdaiSi_prefix_var.h                                                    
     type/SdaiApproved_item.h                                                    type/SdaiSurface_model.h                                                    
        )

set(sdai_ap203_misc_hdrs
     Sdaiclasses.h   schema.h
     SdaiCONFIG_CONTROL_DESIGNNames.h
     SdaiCONFIG_CONTROL_DESIGN.h
   )

# install all headers
set(all_headers ${sdai_ap203_entity_hdrs} ${sdai_ap203_type_hdrs} ${sdai_ap203_misc_hdrs})
foreach( header_file ${all_headers} )
  set(curr_dir)
  get_filename_component(curr_dir ${header_file} PATH)
  get_filename_component(curr_name ${header_file} NAME)
  if (curr_dir)
    install( FILES ${header_file} DESTINATION "include/schemas/sdai_ap203/${curr_dir}" )
  else (curr_dir)
    install( FILES ${header_file} DESTINATION "include/schemas/sdai_ap203" )
  endif (curr_dir)
endforeach()
# implementation files - 3 lists

# unity build: #include small .cc files to reduce the number
# of translation units that must be compiled
if(SC_UNITY_BUILD)
  # turns off include statements within type and entity .cc's - the unity T.U.'s include a unity header
  add_definitions( -DSC_SDAI_UNITY_BUILD)
  set(sdai_ap203_entity_impls SdaiCONFIG_CONTROL_DESIGN_unity_entities.cc)
  set(sdai_ap203_type_impls SdaiCONFIG_CONTROL_DESIGN_unity_types.cc)
else(SC_UNITY_BUILD)
  set(sdai_ap203_entity_impls
     entity/SdaiCartesian_transformation_operator_3d.cc                          entity/SdaiVersioned_action_request.cc                                      
     entity/SdaiManifold_surface_shape_representation.cc                         entity/SdaiCertification.cc                                                 
     entity/SdaiQuantified_assembly_component_usage.cc                           entity/SdaiFaceted_brep.cc                                                  
     entity/SdaiAction_directive.cc                                              entity/SdaiPlane_angle_unit.cc                                              
     entity/SdaiArea_measure_with_unit.cc                                        entity/SdaiSerial_numbered_effectivity.cc                                   
     entity/SdaiOffset_surface.cc                                                entity/SdaiAxis2_placement_2d.cc                                            
     entity/SdaiProduct_related_product_category.cc                              entity/SdaiHyperbola.cc                                                     
     entity/SdaiOrganizational_address.cc                                        entity/SdaiUniform_surface.cc                                               
     entity/SdaiGeometrically_bounded_surface_shape_representation.cc            entity/SdaiAxis1_placement.cc                                               
     entity/SdaiRational_b_spline_curve.cc                                       entity/SdaiAction_request_assignment.cc                                     
     entity/SdaiFace_bound.cc                                                    entity/SdaiLength_measure_with_unit.cc                                      
     entity/SdaiDated_effectivity.cc                                             entity/SdaiDirection.cc                                                     
     entity/SdaiNext_assembly_usage_occurrence.cc                                entity/SdaiBounded_curve.cc                                                 
     entity/SdaiOriented_edge.cc                                                 entity/SdaiPerson.cc                                                        
     entity/SdaiDocument_with_class.cc                                           entity/SdaiConversion_based_unit.cc                                         
     entity/SdaiPoint_on_surface.cc                                              entity/SdaiProduct_definition_formation.cc                                  
     entity/SdaiRepresentation_item.cc                                           entity/SdaiCc_design_person_and_organization_assignment.cc                  
     entity/SdaiOffset_curve_3d.cc                                               entity/SdaiApproval.cc                                                      
     entity/SdaiBoundary_curve.cc                                                entity/SdaiGeometric_representation_context.cc                              
     entity/SdaiAction_status.cc                                                 entity/SdaiApplication_context.cc                                           
     entity/SdaiChange_request.cc                                                entity/SdaiDate_and_time.cc                                                 
     entity/SdaiApproval_date_time.cc                                            entity/SdaiApproval_role.cc                                                 
     entity/SdaiProduct_context.cc                                               entity/SdaiSpherical_surface.cc                                             
     entity/SdaiApplication_protocol_definition.cc                               entity/SdaiSpecified_higher_usage_occurrence.cc                             
     entity/SdaiProduct_definition_formation_with_specified_source.cc            entity/SdaiAction_request_solution.cc                                       
     entity/SdaiUncertainty_measure_with_unit.cc                                 entity/SdaiEdge_based_wireframe_model.cc                                    
     entity/SdaiCartesian_transformation_operator.cc                             entity/SdaiPath.cc                                                          
     entity/SdaiOriented_open_shell.cc                                           entity/SdaiSolid_angle_unit.cc                                              
     entity/SdaiTopological_representation_item.cc                               entity/SdaiConnected_face_set.cc                                            
     entity/SdaiCoordinated_universal_time_offset.cc                             entity/SdaiCurve_replica.cc                                                 
     entity/SdaiQuasi_uniform_surface.cc                                         entity/SdaiSurface_curve.cc                                                 
     entity/SdaiAction_request_status.cc                                         entity/SdaiB_spline_surface.cc                                              
     entity/SdaiReparametrised_composite_curve_segment.cc                        entity/SdaiRepresentation_relationship_with_transformation.cc               
     entity/SdaiPerson_and_organization_role.cc                                  entity/SdaiQuasi_uniform_curve.cc                                           
     entity/SdaiSwept_surface.cc                                                 entity/SdaiProperty_definition.cc                                           
     entity/SdaiGlobal_uncertainty_assigned_context.cc                           entity/SdaiComposite_curve_on_surface.cc                                    
     entity/SdaiOrganization_relationship.cc                                     entity/SdaiParabola.cc                                                      
     entity/SdaiRectangular_composite_surface.cc                                 entity/SdaiElementary_surface.cc                                            
     entity/SdaiLot_effectivity.cc                                               entity/SdaiSurface_of_linear_extrusion.cc                                   
     entity/SdaiShell_based_surface_model.cc                                     entity/SdaiUniform_curve.cc                                                 
     entity/SdaiBezier_curve.cc                                                  entity/SdaiEdge_loop.cc                                                     
     entity/SdaiCalendar_date.cc                                                 entity/SdaiToroidal_surface.cc                                              
     entity/SdaiEdge.cc                                                          entity/SdaiPromissory_usage_occurrence.cc                                   
     entity/SdaiApproval_assignment.cc                                           entity/SdaiConfiguration_item.cc                                            
     entity/SdaiContract_assignment.cc                                           entity/SdaiVector.cc                                                        
     entity/SdaiBounded_pcurve.cc                                                entity/SdaiIntersection_curve.cc                                            
     entity/SdaiTrimmed_curve.cc                                                 entity/SdaiProduct_definition_context.cc                                    
     entity/SdaiBounded_surface_curve.cc                                         entity/SdaiItem_defined_transformation.cc                                   
     entity/SdaiRepresentation.cc                                                entity/SdaiAction_method.cc                                                 
     entity/SdaiProduct_category_relationship.cc                                 entity/SdaiRepresentation_context.cc                                        
     entity/SdaiPlane_angle_measure_with_unit.cc                                 entity/SdaiVertex.cc                                                        
     entity/SdaiProduct_definition_relationship.cc                               entity/SdaiRepresentation_map.cc                                            
     entity/SdaiConfiguration_effectivity.cc                                     entity/SdaiEllipse.cc                                                       
     entity/SdaiManifold_solid_brep.cc                                           entity/SdaiSolid_model.cc                                                   
     entity/SdaiContext_dependent_unit.cc                                        entity/SdaiLoop.cc                                                          
     entity/SdaiAlternate_product_relationship.cc                                entity/SdaiDocument_type.cc                                                 
     entity/SdaiDocument_reference.cc                                            entity/SdaiMechanical_context.cc                                            
     entity/SdaiPlacement.cc                                                     entity/SdaiShell_based_wireframe_model.cc                                   
     entity/SdaiComposite_curve.cc                                               entity/SdaiConic.cc                                                         
     entity/SdaiContract.cc                                                      entity/SdaiDimensional_exponents.cc                                         
     entity/SdaiStart_request.cc                                                 entity/SdaiCc_design_specification_reference.cc                             
     entity/SdaiEffectivity.cc                                                   entity/SdaiSupplied_part_relationship.cc                                    
     entity/SdaiDocument.cc                                                      entity/SdaiContext_dependent_shape_representation.cc                        
     entity/SdaiDegenerate_toroidal_surface.cc                                   entity/SdaiPerson_and_organization_assignment.cc                            
     entity/SdaiOrdinal_date.cc                                                  entity/SdaiFace_outer_bound.cc                                              
     entity/SdaiMass_measure_with_unit.cc                                        entity/SdaiBrep_with_voids.cc                                               
     entity/SdaiWeek_of_year_and_day_date.cc                                     entity/SdaiPoint_on_curve.cc                                                
     entity/SdaiShell_based_wireframe_shape_representation.cc                    entity/SdaiFunctionally_defined_transformation.cc                           
     entity/SdaiMeasure_with_unit.cc                                             entity/SdaiFace_surface.cc                                                  
     entity/SdaiOriented_face.cc                                                 entity/SdaiSurface_of_revolution.cc                                         
     entity/SdaiAdvanced_brep_shape_representation.cc                            entity/SdaiFace.cc                                                          
     entity/SdaiOpen_shell.cc                                                    entity/SdaiEdge_curve.cc                                                    
     entity/SdaiPoint_replica.cc                                                 entity/SdaiProduct.cc                                                       
     entity/SdaiShape_aspect_relationship.cc                                     entity/SdaiRectangular_trimmed_surface.cc                                   
     entity/SdaiPlane.cc                                                         entity/SdaiChange.cc                                                        
     entity/SdaiCircle.cc                                                        entity/SdaiLine.cc                                                          
     entity/SdaiProperty_definition_representation.cc                            entity/SdaiGeometric_curve_set.cc                                           
     entity/SdaiPersonal_address.cc                                              entity/SdaiDocument_relationship.cc                                         
     entity/SdaiPcurve.cc                                                        entity/SdaiOuter_boundary_curve.cc                                          
     entity/SdaiRepresentation_relationship.cc                                   entity/SdaiShape_representation_relationship.cc                             
     entity/SdaiAssembly_component_usage_substitute.cc                           entity/SdaiEvaluated_degenerate_pcurve.cc                                   
     entity/SdaiSolid_angle_measure_with_unit.cc                                 entity/SdaiConnected_edge_set.cc                                            
     entity/SdaiCurve.cc                                                         entity/SdaiDirected_action.cc                                               
     entity/SdaiOrganizational_project.cc                                        entity/SdaiDate.cc                                                          
     entity/SdaiDate_time_role.cc                                                entity/SdaiNamed_unit.cc                                                    
     entity/SdaiDegenerate_pcurve.cc                                             entity/SdaiCurve_bounded_surface.cc                                         
     entity/SdaiClosed_shell.cc                                                  entity/SdaiComposite_curve_segment.cc                                       
     entity/SdaiDesign_make_from_relationship.cc                                 entity/SdaiSurface.cc                                                       
     entity/SdaiDefinitional_representation.cc                                   entity/SdaiProduct_definition_shape.cc                                      
     entity/SdaiSi_unit.cc                                                       entity/SdaiGeometric_set.cc                                                 
     entity/SdaiBezier_surface.cc                                                entity/SdaiCertification_assignment.cc                                      
     entity/SdaiStart_work.cc                                                    entity/SdaiContract_type.cc                                                 
     entity/SdaiB_spline_curve_with_knots.cc                                     entity/SdaiGeometric_representation_item.cc                                 
     entity/SdaiCc_design_approval.cc                                            entity/SdaiEdge_based_wireframe_shape_representation.cc                     
     entity/SdaiGeometrically_bounded_wireframe_shape_representation.cc          entity/SdaiProduct_concept.cc                                               
     entity/SdaiCc_design_contract.cc                                            entity/SdaiSeam_curve.cc                                                    
     entity/SdaiAxis2_placement_3d.cc                                            entity/SdaiRational_b_spline_surface.cc                                     
     entity/SdaiConfiguration_design.cc                                          entity/SdaiDesign_context.cc                                                
     entity/SdaiProduct_definition_with_associated_documents.cc                  entity/SdaiAssembly_component_usage.cc                                      
     entity/SdaiOrganization.cc                                                  entity/SdaiCc_design_certification.cc                                       
     entity/SdaiProduct_definition_usage.cc                                      entity/SdaiB_spline_surface_with_knots.cc                                   
     entity/SdaiCertification_type.cc                                            entity/SdaiOriented_path.cc                                                 
     entity/SdaiSecurity_classification.cc                                       entity/SdaiShape_representation.cc                                          
     entity/SdaiVertex_loop.cc                                                   entity/SdaiApproval_status.cc                                               
     entity/SdaiCartesian_point.cc                                               entity/SdaiDate_and_time_assignment.cc                                      
     entity/SdaiPoint.cc                                                         entity/SdaiAction_assignment.cc                                             
     entity/SdaiProduct_definition.cc                                            entity/SdaiParametric_representation_context.cc                             
     entity/SdaiProduct_concept_context.cc                                       entity/SdaiSurface_patch.cc                                                 
     entity/SdaiLength_unit.cc                                                   entity/SdaiShape_aspect.cc                                                  
     entity/SdaiVolume_measure_with_unit.cc                                      entity/SdaiApplication_context_element.cc                                   
     entity/SdaiAdvanced_face.cc                                                 entity/SdaiSecurity_classification_level.cc                                 
     entity/SdaiApproval_relationship.cc                                         entity/SdaiPolyline.cc                                                      
     entity/SdaiApproval_person_organization.cc                                  entity/SdaiProduct_definition_effectivity.cc                                
     entity/SdaiProduct_category.cc                                              entity/SdaiSurface_replica.cc                                               
     entity/SdaiAddress.cc                                                       entity/SdaiCc_design_security_classification.cc                             
     entity/SdaiExecuted_action.cc                                               entity/SdaiFaceted_brep_shape_representation.cc                             
     entity/SdaiDocument_usage_constraint.cc                                     entity/SdaiVertex_point.cc                                                  
     entity/SdaiCc_design_date_and_time_assignment.cc                            entity/SdaiOriented_closed_shell.cc                                         
     entity/SdaiPerson_and_organization.cc                                       entity/SdaiBounded_surface.cc                                               
     entity/SdaiAction.cc                                                        entity/SdaiCylindrical_surface.cc                                           
     entity/SdaiLocal_time.cc                                                    entity/SdaiMass_unit.cc                                                     
     entity/SdaiVertex_shell.cc                                                  entity/SdaiPoly_loop.cc                                                     
     entity/SdaiWire_shell.cc                                                    entity/SdaiArea_unit.cc                                                     
     entity/SdaiMapped_item.cc                                                   entity/SdaiShape_definition_representation.cc                               
     entity/SdaiVolume_unit.cc                                                   entity/SdaiConical_surface.cc                                               
     entity/SdaiSecurity_classification_assignment.cc                            entity/SdaiFounded_item.cc                                                  
     entity/SdaiGlobal_unit_assigned_context.cc                                  entity/SdaiB_spline_curve.cc                                                
        )

  set(sdai_ap203_type_impls
     type/SdaiCharacterized_definition.cc                                        type/SdaiChange_request_item.cc                                             
     type/SdaiCharacterized_product_definition.cc                                type/SdaiReversible_topology_item.cc                                        
     type/SdaiAxis2_placement.cc                                                 type/SdaiKnot_type_var.cc                                                   
     type/SdaiSpecified_item.cc                                                  type/SdaiTransition_code_var.cc                                             
     type/SdaiMeasure_value.cc                                                   type/SdaiPerson_organization_select.cc                                      
     type/SdaiPreferred_surface_curve_representation_var.cc                      type/SdaiPcurve_or_surface.cc                                               
     type/SdaiB_spline_curve_form_var.cc                                         type/SdaiClassified_item.cc                                                 
     type/SdaiSi_unit_name_var.cc                                                type/SdaiFounded_item_select.cc                                             
     type/SdaiTrimming_preference_var.cc                                         type/SdaiVector_or_direction.cc                                             
     type/SdaiWireframe_model.cc                                                 type/SdaiGeometric_set_select.cc                                            
     type/SdaiStart_request_item.cc                                              type/SdaiB_spline_surface_form_var.cc                                       
     type/SdaiPerson_organization_item.cc                                        type/SdaiDate_time_item.cc                                                  
     type/SdaiShell.cc                                                           type/SdaiTransformation.cc                                                  
     type/SdaiBoolean_operand.cc                                                 type/SdaiCertified_item.cc                                                  
     type/SdaiDate_time_select.cc                                                type/SdaiCurve_on_surface.cc                                                
     type/SdaiTrimming_select.cc                                                 type/SdaiAhead_or_behind_var.cc                                             
     type/SdaiContracted_item.cc                                                 type/SdaiSource_var.cc                                                      
     type/SdaiUnit.cc                                                            type/SdaiReversible_topology.cc                                             
     type/SdaiWork_item.cc                                                       type/SdaiShape_definition.cc                                                
     type/SdaiSupported_item.cc                                                  type/SdaiSi_prefix_var.cc                                                   
     type/SdaiApproved_item.cc                                                   type/SdaiSurface_model.cc                                                   
        )
endif(SC_UNITY_BUILD)

set( sdai_ap203_misc_impls
     SdaiAll.cc    compstructs.cc    schema.cc
     SdaiCONFIG_CONTROL_DESIGN.cc
     SdaiCONFIG_CONTROL_DESIGN.init.cc   )

set(schema_target_files ${sdai_ap203_entity_impls} ${sdai_ap203_type_impls} ${sdai_ap203_misc_impls})
SCHEMA_TARGETS("F:/VS2019/XXX-StepCode/Windows/stepcode/data/ap203/ap203.exp" "config_control_design"
                 "${schema_target_files}")
