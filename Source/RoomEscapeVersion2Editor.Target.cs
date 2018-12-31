// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class RoomEscapeVersion2EditorTarget : TargetRules
{
	public RoomEscapeVersion2EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "RoomEscapeVersion2" } );
	}
}
