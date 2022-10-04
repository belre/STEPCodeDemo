# -----  GENERATED FILE  -----
# -----   Do not edit!   -----

# schema name: dimensional_inspection_schema
# (short name: sdai_ap219)
# 352 entities, 53 types

# targets, logic, etc are within a set of macros shared by all schemas
include(${SC_CMAKE_DIR}/SC_CXX_schema_macros.cmake)
set(sdai_ap219_file_count 820)

PROJECT(sdai_ap219)
# list headers so they can be installed - entity, type, misc
set(sdai_ap219_entity_hdrs
     entity/SdaiComposite_hole.h                                                 entity/SdaiDm_program_run.h                                                 
     entity/SdaiCartesian_transformation_operator_3d.h                           entity/SdaiCylindricity_tolerance.h                                         
     entity/SdaiDmf_surface_of_revolution_dml.h                                  entity/SdaiDm_instanced_feature.h                                           
     entity/SdaiFaceted_brep.h                                                   entity/SdaiHole_bottom.h                                                    
     entity/SdaiPlane_angle_unit.h                                               entity/SdaiRib_top_floor.h                                                  
     entity/SdaiApplied_organization_assignment.h                                entity/SdaiTaper.h                                                          
     entity/SdaiName_attribute.h                                                 entity/SdaiOriented_surface.h                                               
     entity/SdaiAxis2_placement_2d.h                                             entity/SdaiComposite_shape_aspect.h                                         
     entity/SdaiShape_representation_with_parameters.h                           entity/SdaiHyperbola.h                                                      
     entity/SdaiPath_shape_representation.h                                      entity/SdaiShape_aspect_deriving_relationship.h                             
     entity/SdaiTolerance_zone_form.h                                            entity/SdaiUncertainty_qualifier.h                                          
     entity/SdaiOrganizational_address.h                                         entity/SdaiUniform_surface.h                                                
     entity/SdaiLine_profile_tolerance.h                                         entity/SdaiAxis1_placement.h                                                
     entity/SdaiRational_b_spline_curve.h                                        entity/SdaiDmf_cone.h                                                       
     entity/SdaiSymmetry_tolerance.h                                             entity/SdaiApplied_area.h                                                   
     entity/SdaiDm_feature_relationship.h                                        entity/SdaiDirected_dimensional_location.h                                  
     entity/SdaiFace_bound.h                                                     entity/SdaiLength_measure_with_unit.h                                       
     entity/SdaiDirection.h                                                      entity/SdaiTime_unit.h                                                      
     entity/SdaiBounded_curve.h                                                  entity/SdaiOriented_edge.h                                                  
     entity/SdaiPerson.h                                                         entity/SdaiDocument_with_class.h                                            
     entity/SdaiConversion_based_unit.h                                          entity/SdaiDmf_sphere.h                                                     
     entity/SdaiProduct_definition_formation.h                                   entity/SdaiRepresentation_item.h                                            
     entity/SdaiDescriptive_representation_item.h                                entity/SdaiDm_feature_analysis_mode_dml.h                                   
     entity/SdaiGeometric_representation_context.h                               entity/SdaiApplied_date_assignment.h                                        
     entity/SdaiPath_feature_component.h                                         entity/SdaiValue_range.h                                                    
     entity/SdaiBoss.h                                                           entity/SdaiApplication_context.h                                            
     entity/SdaiDate_and_time.h                                                  entity/SdaiPattern_omit_membership.h                                        
     entity/SdaiApex.h                                                           entity/SdaiTolerance_value.h                                                
     entity/SdaiProduct_context.h                                                entity/SdaiSpherical_surface.h                                              
     entity/SdaiApplication_protocol_definition.h                                entity/SdaiExternally_defined_dimension_definition.h                        
     entity/SdaiDimensional_location_with_path.h                                 entity/SdaiPattern_offset_membership.h                                      
     entity/SdaiDescription_attribute.h                                          entity/SdaiDm_point.h                                                       
     entity/SdaiDm_program_identification.h                                      entity/SdaiUncertainty_measure_with_unit.h                                  
     entity/SdaiCartesian_transformation_operator.h                              entity/SdaiDmf_line_closed_parallel.h                                       
     entity/SdaiPath.h                                                           entity/SdaiDm_shape_representation_with_parameters.h                        
     entity/SdaiFeature_component_definition.h                                   entity/SdaiOriented_open_shell.h                                            
     entity/SdaiTolerance_zone.h                                                 entity/SdaiSolid_angle_unit.h                                               
     entity/SdaiRole_association.h                                               entity/SdaiRectangular_closed_profile.h                                     
     entity/SdaiTopological_representation_item.h                                entity/SdaiConnected_face_set.h                                             
     entity/SdaiCoordinated_universal_time_offset.h                              entity/SdaiQuasi_uniform_surface.h                                          
     entity/SdaiSurface_curve.h                                                  entity/SdaiSlot_end.h                                                       
     entity/SdaiB_spline_surface.h                                               entity/SdaiClosed_path_profile.h                                            
     entity/SdaiCylindrical_shape_representation.h                               entity/SdaiDm_parameter_analysis_dml.h                                      
     entity/SdaiEdge_round.h                                                     entity/SdaiPerson_and_organization_role.h                                   
     entity/SdaiQuasi_uniform_curve.h                                            entity/SdaiSwept_surface.h                                                  
     entity/SdaiProperty_definition.h                                            entity/SdaiStraightness_tolerance.h                                         
     entity/SdaiAngular_location.h                                               entity/SdaiGlobal_uncertainty_assigned_context.h                            
     entity/SdaiSpherical_cap.h                                                  entity/SdaiNgon_closed_profile.h                                            
     entity/SdaiRunout_zone_orientation_reference_direction.h                    entity/SdaiAction_resource_type.h                                           
     entity/SdaiChamfer_offset.h                                                 entity/SdaiComposite_curve_on_surface.h                                     
     entity/SdaiDm_dimension_parameter.h                                         entity/SdaiParabola.h                                                       
     entity/SdaiDm_feature_definition.h                                          entity/SdaiDmf_edge_point.h                                                 
     entity/SdaiFlatness_tolerance.h                                             entity/SdaiMeasurment_location.h                                            
     entity/SdaiElementary_surface.h                                             entity/SdaiSurface_of_linear_extrusion.h                                    
     entity/SdaiGeometric_tolerance_relationship.h                               entity/SdaiShape_defining_relationship.h                                    
     entity/SdaiUniform_curve.h                                                  entity/SdaiBezier_curve.h                                                   
     entity/SdaiDmf_arc.h                                                        entity/SdaiEdge_loop.h                                                      
     entity/SdaiCalendar_date.h                                                  entity/SdaiToroidal_surface.h                                               
     entity/SdaiEdge.h                                                           entity/SdaiDmf_plane_closed_parallel.h                                      
     entity/SdaiAction_resource_requirement.h                                    entity/SdaiDmf_line_unbounded.h                                             
     entity/SdaiCircular_closed_profile.h                                        entity/SdaiPosition_tolerance.h                                             
     entity/SdaiVector.h                                                         entity/SdaiPerpendicular_to.h                                               
     entity/SdaiProduct_definition_context.h                                     entity/SdaiGeometric_alignment.h                                            
     entity/SdaiGeometric_intersection.h                                         entity/SdaiDimensional_characteristic_representation.h                      
     entity/SdaiProjected_zone_definition.h                                      entity/SdaiCircular_runout_tolerance.h                                      
     entity/SdaiRepresentation.h                                                 entity/SdaiAction_method.h                                                  
     entity/SdaiCharacterized_object.h                                           entity/SdaiCompound_feature.h                                               
     entity/SdaiRepresentation_context.h                                         entity/SdaiPlane_angle_measure_with_unit.h                                  
     entity/SdaiVertex.h                                                         entity/SdaiLinear_profile.h                                                 
     entity/SdaiRepresentation_map.h                                             entity/SdaiEllipse.h                                                        
     entity/SdaiGeometric_tolerance_with_defined_unit.h                          entity/SdaiManifold_solid_brep.h                                            
     entity/SdaiSolid_model.h                                                    entity/SdaiContext_dependent_unit.h                                         
     entity/SdaiLoop.h                                                           entity/SdaiDocument_type.h                                                  
     entity/SdaiDocument_reference.h                                             entity/SdaiGeometric_tolerance.h                                            
     entity/SdaiPlacement.h                                                      entity/SdaiSlot.h                                                           
     entity/SdaiComposite_curve.h                                                entity/SdaiPerpendicularity_tolerance.h                                     
     entity/SdaiPlus_minus_tolerance.h                                           entity/SdaiConic.h                                                          
     entity/SdaiSquare_u_profile.h                                               entity/SdaiDirection_shape_representation.h                                 
     entity/SdaiDatum_feature.h                                                  entity/SdaiDimensional_exponents.h                                          
     entity/SdaiDm_point_parameter.h                                             entity/SdaiRib_top.h                                                        
     entity/SdaiSymmetric_shape_aspect.h                                         entity/SdaiParallelism_tolerance.h                                          
     entity/SdaiDmf_plane.h                                                      entity/SdaiDocument.h                                                       
     entity/SdaiRemoval_volume.h                                                 entity/SdaiDegenerate_toroidal_surface.h                                    
     entity/SdaiDm_execution_result.h                                            entity/SdaiPerson_and_organization_assignment.h                             
     entity/SdaiFace_outer_bound.h                                               entity/SdaiMass_measure_with_unit.h                                         
     entity/SdaiBrep_with_voids.h                                                entity/SdaiDatum_target.h                                                   
     entity/SdaiDmf_cylinder.h                                                   entity/SdaiDmf_pattern.h                                                    
     entity/SdaiExternally_defined_item.h                                        entity/SdaiOrganization_role.h                                              
     entity/SdaiDm_vector_parameter.h                                            entity/SdaiTotal_runout_tolerance.h                                         
     entity/SdaiNgon_shape_representation.h                                      entity/SdaiProtrusion.h                                                     
     entity/SdaiFunctionally_defined_transformation.h                            entity/SdaiMeasure_with_unit.h                                              
     entity/SdaiFace_surface.h                                                   entity/SdaiOriented_face.h                                                  
     entity/SdaiSurface_of_revolution.h                                          entity/SdaiAngular_size.h                                                   
     entity/SdaiAdvanced_brep_shape_representation.h                             entity/SdaiFace.h                                                           
     entity/SdaiOpen_shell.h                                                     entity/SdaiProperty_definition_relationship.h                               
     entity/SdaiEdge_curve.h                                                     entity/SdaiProfile_floor.h                                                  
     entity/SdaiAction_property.h                                                entity/SdaiProduct.h                                                        
     entity/SdaiDatum_reference.h                                                entity/SdaiShape_aspect_relationship.h                                      
     entity/SdaiId_attribute.h                                                   entity/SdaiPlane.h                                                          
     entity/SdaiPocket_bottom.h                                                  entity/SdaiCircle.h                                                         
     entity/SdaiLine.h                                                           entity/SdaiProperty_definition_representation.h                             
     entity/SdaiFeature_definition.h                                             entity/SdaiGear.h                                                           
     entity/SdaiCompound_representation_item.h                                   entity/SdaiStep.h                                                           
     entity/SdaiVee_profile.h                                                    entity/SdaiPersonal_address.h                                               
     entity/SdaiRevolved_profile.h                                               entity/SdaiPcurve.h                                                         
     entity/SdaiType_qualifier.h                                                 entity/SdaiOpen_path_profile.h                                              
     entity/SdaiOutside_profile.h                                                entity/SdaiResource_requirement_type.h                                      
     entity/SdaiCircular_pattern.h                                               entity/SdaiExternally_defined_feature_definition.h                          
     entity/SdaiCurve.h                                                          entity/SdaiInstanced_feature.h                                              
     entity/SdaiOrganizational_project.h                                         entity/SdaiDate.h                                                           
     entity/SdaiRatio_unit.h                                                     entity/SdaiApplied_document_reference.h                                     
     entity/SdaiNamed_unit.h                                                     entity/SdaiDmf_geometric_surface.h                                          
     entity/SdaiExtension.h                                                      entity/SdaiFeature_pattern.h                                                
     entity/SdaiClosed_shell.h                                                   entity/SdaiComposite_curve_segment.h                                        
     entity/SdaiRound_hole.h                                                     entity/SdaiQualified_representation_item.h                                  
     entity/SdaiTolerance_zone_definition.h                                      entity/SdaiSurface.h                                                        
     entity/SdaiFeature_component_relationship.h                                 entity/SdaiAngularity_tolerance.h                                           
     entity/SdaiDefinitional_representation.h                                    entity/SdaiPrecision_qualifier.h                                            
     entity/SdaiDate_role.h                                                      entity/SdaiProduct_definition_shape.h                                       
     entity/SdaiSi_unit.h                                                        entity/SdaiBezier_surface.h                                                 
     entity/SdaiParallel_offset.h                                                entity/SdaiDm_execution_result_measurement.h                                
     entity/SdaiSurface_profile_tolerance.h                                      entity/SdaiPlanar_shape_representation.h                                    
     entity/SdaiB_spline_curve_with_knots.h                                      entity/SdaiDmf_torus.h                                                      
     entity/SdaiGeometric_representation_item.h                                  entity/SdaiTangent.h                                                        
     entity/SdaiGeometric_tolerance_with_datum_reference.h                       entity/SdaiDerived_unit_element.h                                           
     entity/SdaiOuter_round.h                                                    entity/SdaiDerived_unit.h                                                   
     entity/SdaiReplicate_feature.h                                              entity/SdaiResource_property.h                                              
     entity/SdaiRoundness_tolerance.h                                            entity/SdaiFlat_face.h                                                      
     entity/SdaiAxis2_placement_3d.h                                             entity/SdaiDatum.h                                                          
     entity/SdaiRational_b_spline_surface.h                                      entity/SdaiDm_result_parameter.h                                            
     entity/SdaiRounded_end.h                                                    entity/SdaiDm_analysis_dofs_dml.h                                           
     entity/SdaiCommon_datum.h                                                   entity/SdaiMarking.h                                                        
     entity/SdaiOrganization.h                                                   entity/SdaiTurned_knurl.h                                                   
     entity/SdaiDimensional_location.h                                           entity/SdaiLocation_shape_representation.h                                  
     entity/SdaiReferenced_modified_datum.h                                      entity/SdaiB_spline_surface_with_knots.h                                    
     entity/SdaiDm_parameter_value_limits.h                                      entity/SdaiFace_shape_representation.h                                      
     entity/SdaiModified_geometric_tolerance.h                                   entity/SdaiModified_pattern.h                                               
     entity/SdaiOriented_path.h                                                  entity/SdaiMeasure_qualification.h                                          
     entity/SdaiSecurity_classification.h                                        entity/SdaiShape_representation.h                                           
     entity/SdaiStandard_uncertainty.h                                           entity/SdaiVertex_loop.h                                                    
     entity/SdaiRunout_zone_definition.h                                         entity/SdaiOrganization_assignment.h                                        
     entity/SdaiCartesian_point.h                                                entity/SdaiPoint.h                                                          
     entity/SdaiProduct_definition.h                                             entity/SdaiParametric_representation_context.h                              
     entity/SdaiLimits_and_fits.h                                                entity/SdaiBlock_shape_representation.h                                     
     entity/SdaiApplied_security_classification_assignment.h                     entity/SdaiConcentricity_tolerance.h                                        
     entity/SdaiDmf_circle.h                                                     entity/SdaiDmf_geometric_curve.h                                            
     entity/SdaiLength_unit.h                                                    entity/SdaiShape_aspect.h                                                   
     entity/SdaiApplication_context_element.h                                    entity/SdaiDimension_related_tolerance_zone_element.h                       
     entity/SdaiAdvanced_face.h                                                  entity/SdaiMeasure_representation_item.h                                    
     entity/SdaiObject_role.h                                                    entity/SdaiSecurity_classification_level.h                                  
     entity/SdaiTransition_feature.h                                             entity/SdaiDate_assignment.h                                                
     entity/SdaiPocket.h                                                         entity/SdaiPolyline.h                                                       
     entity/SdaiChamfer.h                                                        entity/SdaiDocument_representation_type.h                                   
     entity/SdaiRunout_zone_orientation.h                                        entity/SdaiDimensional_size_with_path.h                                     
     entity/SdaiDmf_plane_symmetric.h                                            entity/SdaiFillet.h                                                         
     entity/SdaiThread.h                                                         entity/SdaiAddress.h                                                        
     entity/SdaiDerived_shape_aspect.h                                           entity/SdaiDmf_point.h                                                      
     entity/SdaiExecuted_action.h                                                entity/SdaiDocument_usage_constraint.h                                      
     entity/SdaiDmf_line_bounded.h                                               entity/SdaiShape_dimension_representation.h                                 
     entity/SdaiVertex_point.h                                                   entity/SdaiCentre_of_symmetry.h                                             
     entity/SdaiOriented_closed_shell.h                                          entity/SdaiRounded_u_profile.h                                              
     entity/SdaiBoss_top.h                                                       entity/SdaiDimensional_size.h                                               
     entity/SdaiPerson_and_organization.h                                        entity/SdaiBounded_surface.h                                                
     entity/SdaiRatio_measure_with_unit.h                                        entity/SdaiRectangular_pattern.h                                            
     entity/SdaiExternal_source.h                                                entity/SdaiTee_profile.h                                                    
     entity/SdaiAction.h                                                         entity/SdaiCylindrical_surface.h                                            
     entity/SdaiLocal_time.h                                                     entity/SdaiMass_unit.h                                                      
     entity/SdaiCoaxiality_tolerance.h                                           entity/SdaiPoly_loop.h                                                      
     entity/SdaiAction_resource.h                                                entity/SdaiMapped_item.h                                                    
     entity/SdaiShape_definition_representation.h                                entity/SdaiConical_surface.h                                                
     entity/SdaiDm_tolerance_analysis_mode_dml.h                                 entity/SdaiDmf_ellipse.h                                                    
     entity/SdaiSecurity_classification_assignment.h                             entity/SdaiFounded_item.h                                                   
     entity/SdaiGlobal_unit_assigned_context.h                                   entity/SdaiApplied_person_organization_assignment.h                         
     entity/SdaiDimensional_measurement_representation.h                         entity/SdaiDmf_generic_feature.h                                            
     entity/SdaiTime_measure_with_unit.h                                         entity/SdaiAction_property_representation.h                                 
     entity/SdaiB_spline_curve.h                                                 entity/SdaiPartial_circular_profile.h                                       
        )

set(sdai_ap219_type_hdrs
     type/SdaiCharacterized_definition.h                                         type/SdaiCharacterized_product_definition.h                                 
     type/SdaiReversible_topology_item.h                                         type/SdaiAxis2_placement.h                                                  
     type/SdaiLimit_condition_var.h                                              type/SdaiKnot_type_var.h                                                    
     type/SdaiTransition_code_var.h                                              type/SdaiCompound_item_definition.h                                         
     type/SdaiRepresented_definition.h                                           type/SdaiMeasure_value.h                                                    
     type/SdaiPerson_organization_select.h                                       type/SdaiPreferred_surface_curve_representation_var.h                       
     type/SdaiProperty_or_shape_select.h                                         type/SdaiPcurve_or_surface.h                                                
     type/SdaiAttribute_type.h                                                   type/SdaiId_attribute_select.h                                              
     type/SdaiB_spline_curve_form_var.h                                          type/SdaiSecurity_classification_item.h                                     
     type/SdaiDimensional_characteristic.h                                       type/SdaiDocument_reference_item.h                                          
     type/SdaiSi_unit_name_var.h                                                 type/SdaiFounded_item_select.h                                              
     type/SdaiSource_item.h                                                      type/SdaiDate_time_or_event_occurrence.h                                    
     type/SdaiDerived_property_select.h                                          type/SdaiVector_or_direction.h                                              
     type/SdaiGeometric_set_select.h                                             type/SdaiB_spline_surface_form_var.h                                        
     type/SdaiShell.h                                                            type/SdaiTransformation.h                                                   
     type/SdaiBoolean_operand.h                                                  type/SdaiDate_time_select.h                                                 
     type/SdaiOrganization_item.h                                                type/SdaiProduct_or_formation_or_definition.h                               
     type/SdaiCurve_on_surface.h                                                 type/SdaiTrimming_select.h                                                  
     type/SdaiRole_select.h                                                      type/SdaiAhead_or_behind_var.h                                              
     type/SdaiAngle_relator_var.h                                                type/SdaiCharacterized_action_definition.h                                  
     type/SdaiTolerance_method_definition.h                                      type/SdaiDescription_attribute_select.h                                     
     type/SdaiCharacterized_resource_definition.h                                type/SdaiName_attribute_select.h                                            
     type/SdaiUnit.h                                                             type/SdaiDate_item.h                                                        
     type/SdaiReversible_topology.h                                              type/SdaiShape_definition.h                                                 
     type/SdaiSupported_item.h                                                   type/SdaiTolerance_select.h                                                 
     type/SdaiPerson_and_organization_item.h                                     type/SdaiSi_prefix_var.h                                                    
     type/SdaiValue_qualifier.h                                                     )

set(sdai_ap219_misc_hdrs
     Sdaiclasses.h   schema.h
     SdaiDIMENSIONAL_INSPECTION_SCHEMANames.h
     SdaiDIMENSIONAL_INSPECTION_SCHEMA.h
   )

# install all headers
set(all_headers ${sdai_ap219_entity_hdrs} ${sdai_ap219_type_hdrs} ${sdai_ap219_misc_hdrs})
foreach( header_file ${all_headers} )
  set(curr_dir)
  get_filename_component(curr_dir ${header_file} PATH)
  get_filename_component(curr_name ${header_file} NAME)
  if (curr_dir)
    install( FILES ${header_file} DESTINATION "include/schemas/sdai_ap219/${curr_dir}" )
  else (curr_dir)
    install( FILES ${header_file} DESTINATION "include/schemas/sdai_ap219" )
  endif (curr_dir)
endforeach()
# implementation files - 3 lists

# unity build: #include small .cc files to reduce the number
# of translation units that must be compiled
if(SC_UNITY_BUILD)
  # turns off include statements within type and entity .cc's - the unity T.U.'s include a unity header
  add_definitions( -DSC_SDAI_UNITY_BUILD)
  set(sdai_ap219_entity_impls SdaiDIMENSIONAL_INSPECTION_SCHEMA_unity_entities.cc)
  set(sdai_ap219_type_impls SdaiDIMENSIONAL_INSPECTION_SCHEMA_unity_types.cc)
else(SC_UNITY_BUILD)
  set(sdai_ap219_entity_impls
     entity/SdaiComposite_hole.cc                                                entity/SdaiDm_program_run.cc                                                
     entity/SdaiCartesian_transformation_operator_3d.cc                          entity/SdaiCylindricity_tolerance.cc                                        
     entity/SdaiDmf_surface_of_revolution_dml.cc                                 entity/SdaiDm_instanced_feature.cc                                          
     entity/SdaiFaceted_brep.cc                                                  entity/SdaiHole_bottom.cc                                                   
     entity/SdaiPlane_angle_unit.cc                                              entity/SdaiRib_top_floor.cc                                                 
     entity/SdaiApplied_organization_assignment.cc                               entity/SdaiTaper.cc                                                         
     entity/SdaiName_attribute.cc                                                entity/SdaiOriented_surface.cc                                              
     entity/SdaiAxis2_placement_2d.cc                                            entity/SdaiComposite_shape_aspect.cc                                        
     entity/SdaiShape_representation_with_parameters.cc                          entity/SdaiHyperbola.cc                                                     
     entity/SdaiPath_shape_representation.cc                                     entity/SdaiShape_aspect_deriving_relationship.cc                            
     entity/SdaiTolerance_zone_form.cc                                           entity/SdaiUncertainty_qualifier.cc                                         
     entity/SdaiOrganizational_address.cc                                        entity/SdaiUniform_surface.cc                                               
     entity/SdaiLine_profile_tolerance.cc                                        entity/SdaiAxis1_placement.cc                                               
     entity/SdaiRational_b_spline_curve.cc                                       entity/SdaiDmf_cone.cc                                                      
     entity/SdaiSymmetry_tolerance.cc                                            entity/SdaiApplied_area.cc                                                  
     entity/SdaiDm_feature_relationship.cc                                       entity/SdaiDirected_dimensional_location.cc                                 
     entity/SdaiFace_bound.cc                                                    entity/SdaiLength_measure_with_unit.cc                                      
     entity/SdaiDirection.cc                                                     entity/SdaiTime_unit.cc                                                     
     entity/SdaiBounded_curve.cc                                                 entity/SdaiOriented_edge.cc                                                 
     entity/SdaiPerson.cc                                                        entity/SdaiDocument_with_class.cc                                           
     entity/SdaiConversion_based_unit.cc                                         entity/SdaiDmf_sphere.cc                                                    
     entity/SdaiProduct_definition_formation.cc                                  entity/SdaiRepresentation_item.cc                                           
     entity/SdaiDescriptive_representation_item.cc                               entity/SdaiDm_feature_analysis_mode_dml.cc                                  
     entity/SdaiGeometric_representation_context.cc                              entity/SdaiApplied_date_assignment.cc                                       
     entity/SdaiPath_feature_component.cc                                        entity/SdaiValue_range.cc                                                   
     entity/SdaiBoss.cc                                                          entity/SdaiApplication_context.cc                                           
     entity/SdaiDate_and_time.cc                                                 entity/SdaiPattern_omit_membership.cc                                       
     entity/SdaiApex.cc                                                          entity/SdaiTolerance_value.cc                                               
     entity/SdaiProduct_context.cc                                               entity/SdaiSpherical_surface.cc                                             
     entity/SdaiApplication_protocol_definition.cc                               entity/SdaiExternally_defined_dimension_definition.cc                       
     entity/SdaiDimensional_location_with_path.cc                                entity/SdaiPattern_offset_membership.cc                                     
     entity/SdaiDescription_attribute.cc                                         entity/SdaiDm_point.cc                                                      
     entity/SdaiDm_program_identification.cc                                     entity/SdaiUncertainty_measure_with_unit.cc                                 
     entity/SdaiCartesian_transformation_operator.cc                             entity/SdaiDmf_line_closed_parallel.cc                                      
     entity/SdaiPath.cc                                                          entity/SdaiDm_shape_representation_with_parameters.cc                       
     entity/SdaiFeature_component_definition.cc                                  entity/SdaiOriented_open_shell.cc                                           
     entity/SdaiTolerance_zone.cc                                                entity/SdaiSolid_angle_unit.cc                                              
     entity/SdaiRole_association.cc                                              entity/SdaiRectangular_closed_profile.cc                                    
     entity/SdaiTopological_representation_item.cc                               entity/SdaiConnected_face_set.cc                                            
     entity/SdaiCoordinated_universal_time_offset.cc                             entity/SdaiQuasi_uniform_surface.cc                                         
     entity/SdaiSurface_curve.cc                                                 entity/SdaiSlot_end.cc                                                      
     entity/SdaiB_spline_surface.cc                                              entity/SdaiClosed_path_profile.cc                                           
     entity/SdaiCylindrical_shape_representation.cc                              entity/SdaiDm_parameter_analysis_dml.cc                                     
     entity/SdaiEdge_round.cc                                                    entity/SdaiPerson_and_organization_role.cc                                  
     entity/SdaiQuasi_uniform_curve.cc                                           entity/SdaiSwept_surface.cc                                                 
     entity/SdaiProperty_definition.cc                                           entity/SdaiStraightness_tolerance.cc                                        
     entity/SdaiAngular_location.cc                                              entity/SdaiGlobal_uncertainty_assigned_context.cc                           
     entity/SdaiSpherical_cap.cc                                                 entity/SdaiNgon_closed_profile.cc                                           
     entity/SdaiRunout_zone_orientation_reference_direction.cc                   entity/SdaiAction_resource_type.cc                                          
     entity/SdaiChamfer_offset.cc                                                entity/SdaiComposite_curve_on_surface.cc                                    
     entity/SdaiDm_dimension_parameter.cc                                        entity/SdaiParabola.cc                                                      
     entity/SdaiDm_feature_definition.cc                                         entity/SdaiDmf_edge_point.cc                                                
     entity/SdaiFlatness_tolerance.cc                                            entity/SdaiMeasurment_location.cc                                           
     entity/SdaiElementary_surface.cc                                            entity/SdaiSurface_of_linear_extrusion.cc                                   
     entity/SdaiGeometric_tolerance_relationship.cc                              entity/SdaiShape_defining_relationship.cc                                   
     entity/SdaiUniform_curve.cc                                                 entity/SdaiBezier_curve.cc                                                  
     entity/SdaiDmf_arc.cc                                                       entity/SdaiEdge_loop.cc                                                     
     entity/SdaiCalendar_date.cc                                                 entity/SdaiToroidal_surface.cc                                              
     entity/SdaiEdge.cc                                                          entity/SdaiDmf_plane_closed_parallel.cc                                     
     entity/SdaiAction_resource_requirement.cc                                   entity/SdaiDmf_line_unbounded.cc                                            
     entity/SdaiCircular_closed_profile.cc                                       entity/SdaiPosition_tolerance.cc                                            
     entity/SdaiVector.cc                                                        entity/SdaiPerpendicular_to.cc                                              
     entity/SdaiProduct_definition_context.cc                                    entity/SdaiGeometric_alignment.cc                                           
     entity/SdaiGeometric_intersection.cc                                        entity/SdaiDimensional_characteristic_representation.cc                     
     entity/SdaiProjected_zone_definition.cc                                     entity/SdaiCircular_runout_tolerance.cc                                     
     entity/SdaiRepresentation.cc                                                entity/SdaiAction_method.cc                                                 
     entity/SdaiCharacterized_object.cc                                          entity/SdaiCompound_feature.cc                                              
     entity/SdaiRepresentation_context.cc                                        entity/SdaiPlane_angle_measure_with_unit.cc                                 
     entity/SdaiVertex.cc                                                        entity/SdaiLinear_profile.cc                                                
     entity/SdaiRepresentation_map.cc                                            entity/SdaiEllipse.cc                                                       
     entity/SdaiGeometric_tolerance_with_defined_unit.cc                         entity/SdaiManifold_solid_brep.cc                                           
     entity/SdaiSolid_model.cc                                                   entity/SdaiContext_dependent_unit.cc                                        
     entity/SdaiLoop.cc                                                          entity/SdaiDocument_type.cc                                                 
     entity/SdaiDocument_reference.cc                                            entity/SdaiGeometric_tolerance.cc                                           
     entity/SdaiPlacement.cc                                                     entity/SdaiSlot.cc                                                          
     entity/SdaiComposite_curve.cc                                               entity/SdaiPerpendicularity_tolerance.cc                                    
     entity/SdaiPlus_minus_tolerance.cc                                          entity/SdaiConic.cc                                                         
     entity/SdaiSquare_u_profile.cc                                              entity/SdaiDirection_shape_representation.cc                                
     entity/SdaiDatum_feature.cc                                                 entity/SdaiDimensional_exponents.cc                                         
     entity/SdaiDm_point_parameter.cc                                            entity/SdaiRib_top.cc                                                       
     entity/SdaiSymmetric_shape_aspect.cc                                        entity/SdaiParallelism_tolerance.cc                                         
     entity/SdaiDmf_plane.cc                                                     entity/SdaiDocument.cc                                                      
     entity/SdaiRemoval_volume.cc                                                entity/SdaiDegenerate_toroidal_surface.cc                                   
     entity/SdaiDm_execution_result.cc                                           entity/SdaiPerson_and_organization_assignment.cc                            
     entity/SdaiFace_outer_bound.cc                                              entity/SdaiMass_measure_with_unit.cc                                        
     entity/SdaiBrep_with_voids.cc                                               entity/SdaiDatum_target.cc                                                  
     entity/SdaiDmf_cylinder.cc                                                  entity/SdaiDmf_pattern.cc                                                   
     entity/SdaiExternally_defined_item.cc                                       entity/SdaiOrganization_role.cc                                             
     entity/SdaiDm_vector_parameter.cc                                           entity/SdaiTotal_runout_tolerance.cc                                        
     entity/SdaiNgon_shape_representation.cc                                     entity/SdaiProtrusion.cc                                                    
     entity/SdaiFunctionally_defined_transformation.cc                           entity/SdaiMeasure_with_unit.cc                                             
     entity/SdaiFace_surface.cc                                                  entity/SdaiOriented_face.cc                                                 
     entity/SdaiSurface_of_revolution.cc                                         entity/SdaiAngular_size.cc                                                  
     entity/SdaiAdvanced_brep_shape_representation.cc                            entity/SdaiFace.cc                                                          
     entity/SdaiOpen_shell.cc                                                    entity/SdaiProperty_definition_relationship.cc                              
     entity/SdaiEdge_curve.cc                                                    entity/SdaiProfile_floor.cc                                                 
     entity/SdaiAction_property.cc                                               entity/SdaiProduct.cc                                                       
     entity/SdaiDatum_reference.cc                                               entity/SdaiShape_aspect_relationship.cc                                     
     entity/SdaiId_attribute.cc                                                  entity/SdaiPlane.cc                                                         
     entity/SdaiPocket_bottom.cc                                                 entity/SdaiCircle.cc                                                        
     entity/SdaiLine.cc                                                          entity/SdaiProperty_definition_representation.cc                            
     entity/SdaiFeature_definition.cc                                            entity/SdaiGear.cc                                                          
     entity/SdaiCompound_representation_item.cc                                  entity/SdaiStep.cc                                                          
     entity/SdaiVee_profile.cc                                                   entity/SdaiPersonal_address.cc                                              
     entity/SdaiRevolved_profile.cc                                              entity/SdaiPcurve.cc                                                        
     entity/SdaiType_qualifier.cc                                                entity/SdaiOpen_path_profile.cc                                             
     entity/SdaiOutside_profile.cc                                               entity/SdaiResource_requirement_type.cc                                     
     entity/SdaiCircular_pattern.cc                                              entity/SdaiExternally_defined_feature_definition.cc                         
     entity/SdaiCurve.cc                                                         entity/SdaiInstanced_feature.cc                                             
     entity/SdaiOrganizational_project.cc                                        entity/SdaiDate.cc                                                          
     entity/SdaiRatio_unit.cc                                                    entity/SdaiApplied_document_reference.cc                                    
     entity/SdaiNamed_unit.cc                                                    entity/SdaiDmf_geometric_surface.cc                                         
     entity/SdaiExtension.cc                                                     entity/SdaiFeature_pattern.cc                                               
     entity/SdaiClosed_shell.cc                                                  entity/SdaiComposite_curve_segment.cc                                       
     entity/SdaiRound_hole.cc                                                    entity/SdaiQualified_representation_item.cc                                 
     entity/SdaiTolerance_zone_definition.cc                                     entity/SdaiSurface.cc                                                       
     entity/SdaiFeature_component_relationship.cc                                entity/SdaiAngularity_tolerance.cc                                          
     entity/SdaiDefinitional_representation.cc                                   entity/SdaiPrecision_qualifier.cc                                           
     entity/SdaiDate_role.cc                                                     entity/SdaiProduct_definition_shape.cc                                      
     entity/SdaiSi_unit.cc                                                       entity/SdaiBezier_surface.cc                                                
     entity/SdaiParallel_offset.cc                                               entity/SdaiDm_execution_result_measurement.cc                               
     entity/SdaiSurface_profile_tolerance.cc                                     entity/SdaiPlanar_shape_representation.cc                                   
     entity/SdaiB_spline_curve_with_knots.cc                                     entity/SdaiDmf_torus.cc                                                     
     entity/SdaiGeometric_representation_item.cc                                 entity/SdaiTangent.cc                                                       
     entity/SdaiGeometric_tolerance_with_datum_reference.cc                      entity/SdaiDerived_unit_element.cc                                          
     entity/SdaiOuter_round.cc                                                   entity/SdaiDerived_unit.cc                                                  
     entity/SdaiReplicate_feature.cc                                             entity/SdaiResource_property.cc                                             
     entity/SdaiRoundness_tolerance.cc                                           entity/SdaiFlat_face.cc                                                     
     entity/SdaiAxis2_placement_3d.cc                                            entity/SdaiDatum.cc                                                         
     entity/SdaiRational_b_spline_surface.cc                                     entity/SdaiDm_result_parameter.cc                                           
     entity/SdaiRounded_end.cc                                                   entity/SdaiDm_analysis_dofs_dml.cc                                          
     entity/SdaiCommon_datum.cc                                                  entity/SdaiMarking.cc                                                       
     entity/SdaiOrganization.cc                                                  entity/SdaiTurned_knurl.cc                                                  
     entity/SdaiDimensional_location.cc                                          entity/SdaiLocation_shape_representation.cc                                 
     entity/SdaiReferenced_modified_datum.cc                                     entity/SdaiB_spline_surface_with_knots.cc                                   
     entity/SdaiDm_parameter_value_limits.cc                                     entity/SdaiFace_shape_representation.cc                                     
     entity/SdaiModified_geometric_tolerance.cc                                  entity/SdaiModified_pattern.cc                                              
     entity/SdaiOriented_path.cc                                                 entity/SdaiMeasure_qualification.cc                                         
     entity/SdaiSecurity_classification.cc                                       entity/SdaiShape_representation.cc                                          
     entity/SdaiStandard_uncertainty.cc                                          entity/SdaiVertex_loop.cc                                                   
     entity/SdaiRunout_zone_definition.cc                                        entity/SdaiOrganization_assignment.cc                                       
     entity/SdaiCartesian_point.cc                                               entity/SdaiPoint.cc                                                         
     entity/SdaiProduct_definition.cc                                            entity/SdaiParametric_representation_context.cc                             
     entity/SdaiLimits_and_fits.cc                                               entity/SdaiBlock_shape_representation.cc                                    
     entity/SdaiApplied_security_classification_assignment.cc                    entity/SdaiConcentricity_tolerance.cc                                       
     entity/SdaiDmf_circle.cc                                                    entity/SdaiDmf_geometric_curve.cc                                           
     entity/SdaiLength_unit.cc                                                   entity/SdaiShape_aspect.cc                                                  
     entity/SdaiApplication_context_element.cc                                   entity/SdaiDimension_related_tolerance_zone_element.cc                      
     entity/SdaiAdvanced_face.cc                                                 entity/SdaiMeasure_representation_item.cc                                   
     entity/SdaiObject_role.cc                                                   entity/SdaiSecurity_classification_level.cc                                 
     entity/SdaiTransition_feature.cc                                            entity/SdaiDate_assignment.cc                                               
     entity/SdaiPocket.cc                                                        entity/SdaiPolyline.cc                                                      
     entity/SdaiChamfer.cc                                                       entity/SdaiDocument_representation_type.cc                                  
     entity/SdaiRunout_zone_orientation.cc                                       entity/SdaiDimensional_size_with_path.cc                                    
     entity/SdaiDmf_plane_symmetric.cc                                           entity/SdaiFillet.cc                                                        
     entity/SdaiThread.cc                                                        entity/SdaiAddress.cc                                                       
     entity/SdaiDerived_shape_aspect.cc                                          entity/SdaiDmf_point.cc                                                     
     entity/SdaiExecuted_action.cc                                               entity/SdaiDocument_usage_constraint.cc                                     
     entity/SdaiDmf_line_bounded.cc                                              entity/SdaiShape_dimension_representation.cc                                
     entity/SdaiVertex_point.cc                                                  entity/SdaiCentre_of_symmetry.cc                                            
     entity/SdaiOriented_closed_shell.cc                                         entity/SdaiRounded_u_profile.cc                                             
     entity/SdaiBoss_top.cc                                                      entity/SdaiDimensional_size.cc                                              
     entity/SdaiPerson_and_organization.cc                                       entity/SdaiBounded_surface.cc                                               
     entity/SdaiRatio_measure_with_unit.cc                                       entity/SdaiRectangular_pattern.cc                                           
     entity/SdaiExternal_source.cc                                               entity/SdaiTee_profile.cc                                                   
     entity/SdaiAction.cc                                                        entity/SdaiCylindrical_surface.cc                                           
     entity/SdaiLocal_time.cc                                                    entity/SdaiMass_unit.cc                                                     
     entity/SdaiCoaxiality_tolerance.cc                                          entity/SdaiPoly_loop.cc                                                     
     entity/SdaiAction_resource.cc                                               entity/SdaiMapped_item.cc                                                   
     entity/SdaiShape_definition_representation.cc                               entity/SdaiConical_surface.cc                                               
     entity/SdaiDm_tolerance_analysis_mode_dml.cc                                entity/SdaiDmf_ellipse.cc                                                   
     entity/SdaiSecurity_classification_assignment.cc                            entity/SdaiFounded_item.cc                                                  
     entity/SdaiGlobal_unit_assigned_context.cc                                  entity/SdaiApplied_person_organization_assignment.cc                        
     entity/SdaiDimensional_measurement_representation.cc                        entity/SdaiDmf_generic_feature.cc                                           
     entity/SdaiTime_measure_with_unit.cc                                        entity/SdaiAction_property_representation.cc                                
     entity/SdaiB_spline_curve.cc                                                entity/SdaiPartial_circular_profile.cc                                      
        )

  set(sdai_ap219_type_impls
     type/SdaiCharacterized_definition.cc                                        type/SdaiCharacterized_product_definition.cc                                
     type/SdaiReversible_topology_item.cc                                        type/SdaiAxis2_placement.cc                                                 
     type/SdaiLimit_condition_var.cc                                             type/SdaiKnot_type_var.cc                                                   
     type/SdaiTransition_code_var.cc                                             type/SdaiCompound_item_definition.cc                                        
     type/SdaiRepresented_definition.cc                                          type/SdaiMeasure_value.cc                                                   
     type/SdaiPerson_organization_select.cc                                      type/SdaiPreferred_surface_curve_representation_var.cc                      
     type/SdaiProperty_or_shape_select.cc                                        type/SdaiPcurve_or_surface.cc                                               
     type/SdaiAttribute_type.cc                                                  type/SdaiId_attribute_select.cc                                             
     type/SdaiB_spline_curve_form_var.cc                                         type/SdaiSecurity_classification_item.cc                                    
     type/SdaiDimensional_characteristic.cc                                      type/SdaiDocument_reference_item.cc                                         
     type/SdaiSi_unit_name_var.cc                                                type/SdaiFounded_item_select.cc                                             
     type/SdaiSource_item.cc                                                     type/SdaiDate_time_or_event_occurrence.cc                                   
     type/SdaiDerived_property_select.cc                                         type/SdaiVector_or_direction.cc                                             
     type/SdaiGeometric_set_select.cc                                            type/SdaiB_spline_surface_form_var.cc                                       
     type/SdaiShell.cc                                                           type/SdaiTransformation.cc                                                  
     type/SdaiBoolean_operand.cc                                                 type/SdaiDate_time_select.cc                                                
     type/SdaiOrganization_item.cc                                               type/SdaiProduct_or_formation_or_definition.cc                              
     type/SdaiCurve_on_surface.cc                                                type/SdaiTrimming_select.cc                                                 
     type/SdaiRole_select.cc                                                     type/SdaiAhead_or_behind_var.cc                                             
     type/SdaiAngle_relator_var.cc                                               type/SdaiCharacterized_action_definition.cc                                 
     type/SdaiTolerance_method_definition.cc                                     type/SdaiDescription_attribute_select.cc                                    
     type/SdaiCharacterized_resource_definition.cc                               type/SdaiName_attribute_select.cc                                           
     type/SdaiUnit.cc                                                            type/SdaiDate_item.cc                                                       
     type/SdaiReversible_topology.cc                                             type/SdaiShape_definition.cc                                                
     type/SdaiSupported_item.cc                                                  type/SdaiTolerance_select.cc                                                
     type/SdaiPerson_and_organization_item.cc                                    type/SdaiSi_prefix_var.cc                                                   
     type/SdaiValue_qualifier.cc                                                    )
endif(SC_UNITY_BUILD)

set( sdai_ap219_misc_impls
     SdaiAll.cc    compstructs.cc    schema.cc
     SdaiDIMENSIONAL_INSPECTION_SCHEMA.cc
     SdaiDIMENSIONAL_INSPECTION_SCHEMA.init.cc   )

set(schema_target_files ${sdai_ap219_entity_impls} ${sdai_ap219_type_impls} ${sdai_ap219_misc_impls})
SCHEMA_TARGETS("F:/VS2019/XXX-StepCode/Windows/stepcode/data/ap219/10303-219-AIM-long.exp" "dimensional_inspection_schema"
                 "${schema_target_files}")
